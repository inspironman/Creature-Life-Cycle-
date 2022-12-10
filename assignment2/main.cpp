/// Name   : Deepak Kumar Upadhayay
/// Neptun : DD79DY
/// TASK   : 8







#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "radiation.h"
#include "creature.h"
#include <exception>
using namespace std;
void create(const string &str, vector<Plants*> &plants, vector<radiation*> &radiations)
{
    try
    {
    ifstream f(str);
    if(f.fail()) { cout << "Wrong file name!\n"; exit(1);}
    int n; f >> n;
    plants.resize(n);
    radiations.clear();
    radiations.push_back(No_radiation::instance());
    for(int i=0;i<n;++i)
     {
         string plantName, plantType; int plantLevel;
         f >> plantName >> plantType >> plantLevel;
         if(plantType == "wom")
         {
              plants[i] = new Wombleroot(plantName,plantLevel);
         }
         else if(plantType == "wit")
         {
             plants[i] = new Wittenroot(plantName,plantLevel);
         }
         else if(plantType == "wor")
         {
             plants[i] = new Woreroot(plantName,plantLevel);
         }
     }
    }
    catch(exception g)
    {
        cout << g.what();
    }
}

void simulate (vector<Plants*> &plants, vector<radiation*> &radiations, vector <Plants*> &ans,bool &s)
{
    try
    {
        if(s)
        {
    int j = 0;
    bool l = true;
    bool c = false;
    int reqAlpha;
    int reqDelta;
    string rad = "No Radiation";



    int p = 10;


    while (p)
    {
            cout<<"#############################################################"<<endl;
            cout<<endl;
            cout<<"Day "<<j+1<<endl;
            cout<<"Radiation of the day is " << rad << endl ;
            cout<<endl;

//        if (c && radiations[j] == No_radiation::instance())
//        {
//            cout << "Two Consecutive days founded with No Radiations " << endl;
//            l = false;
//        }
//        else
//        {
//            l = true;
//        }
//         if( radiations[j] == No_radiation::instance() )
//         {
//             c = true;
//         }
//         else
//         {
//             c = false;
//         }

        reqAlpha = 0 , reqDelta = 0;
        for (unsigned int i = 0; i < plants.size(); i++) // summing up the alpha and delta demand
        {
            if(plants[i]->alive())
            {
                reqAlpha+= plants[i]->getAlpha();
                reqDelta+= plants[i]->getDelta();
            }
        }
            if(reqAlpha > (3+reqDelta))
                {
                    radiations[j+1] =  Alpha::instance();
                    rad = "Alpha";
                }
            else if(reqDelta > (3+reqAlpha))
                {
                    radiations[j+1] =  Delta::instance();
                    rad = "Delta";
                }
            else
                {
                    radiations[j+1] = No_radiation::instance();
                    rad = "No Radiation";
                }
         for(unsigned int k=0;k < plants.size();k++)
        {
           if(plants[k]->alive())
            {
            plants[k]->influence(radiations[j]);
            cout << "====================================================" << endl;
            cout << "Name of the plant is " << plants[k]->name() << endl;
             if(plants[k]->alive())
            {
                cout << plants[k]->name() <<" is alive"<<endl;
                cout << "Energy level " << plants[k]->getPower() << endl;
            }
            else
            {
                cout << plants[k]->name() <<" is dead"<<endl;
                plants.erase(plants.begin()+k);
                k -= 1;
            }
            }
        }

        cout<<"\n \nRadiation of next day will be " << rad << endl ;
        cout<<"#############################################################"<<endl<<endl<<endl<<endl;
        j++;
        p--;
    }
      for(unsigned int i = 0; i < plants.size(); i++)
      {
          ans.push_back(plants[i]);
      }
        }

        else
        {
            int j = 0;
            bool l = false;
            int reqAlpha;
            int reqDelta;

             while (true)
    {
        if (l && radiations[j] == No_radiation::instance())
        {
            break;
            //exit(1);
        }
         if( radiations[j] == No_radiation::instance() )
         {
             l = true;
         }
        reqAlpha = 0 , reqDelta = 0;
        for (unsigned int i = 0; i < plants.size(); i++) // summing up the alpha and delta demand
        {
            if(plants[i]->alive())
            {
                reqAlpha+= plants[i]->getAlpha();
                reqDelta+= plants[i]->getDelta();
            }
        }
            if(reqAlpha > (3+reqDelta))
                {
                    radiations[j+1] =  Alpha::instance();
                }
            else if(reqDelta > (3+reqAlpha))
                {
                    radiations[j+1] =  Delta::instance();
                }
            else
                {
                    radiations[j+1] = No_radiation::instance();
                }
         for(unsigned int k=0;k < plants.size();k++)
        {
           if(plants[k]->alive())
            {
            plants[k]->influence(radiations[j]);
             if(plants[k]->alive())
            {
            }
            else
            {
                plants.erase(plants.begin()+k);
                k -= 1;
            }
            }
        }
        j++;
    }
      for(unsigned int i = 0; i < plants.size(); i++)
      {
          ans.push_back(plants[i]);
      }
        }
  }
  catch (exception e)
  {
      cout<<e.what();
  }
}


// destroying plants
void destroyplants(vector<Plants*> &plants)
{
    for(unsigned int i=0;i<plants.size(); i++) delete plants[i];
}
//destroying radiations
void destroyradiation()
{
    No_radiation::destroy();
    Alpha::destroy();
    Delta::destroy();
}


#define NORMAL_MODE
#ifndef NORMAL_MODE
int main()
{
    vector<Plants*> plants;
    vector<Plants*> ans;
    ans.clear();
    bool s = true;
    vector<radiation*> radiations;
    create("input5.txt",plants,radiations);
    simulate(plants,radiations,ans,s);
    cout<<endl<<endl<<endl;
//    for(unsigned int i = 0; i < ans.size();i++)
//    {
//        cout << "Name of the plant is " << plants[i]->name() << endl;
//             if(plants[i]->alive())
//            {
//                cout << plants[i]->name() <<" is alive"<<endl;
//                cout << "Energy level " << plants[i]->getPower() << endl;
//            }
//            else
//            {
//                cout << plants[i]->name() <<" is dead"<<endl;
//            }
//    }
       destroyplants(plants);
       destroyradiation();
    return 0;
}
#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
TEST_CASE("1", "input2.txt")
{
    vector<radiation*> radiations;
    vector<Plants*> plants;
    bool s = false;
    vector <Plants*> ans;
    create("input.txt", plants, radiations);
    simulate(plants,radiations,ans,s);
    CHECK(ans.size() == 3);
    ans.clear();
    destroyplants(plants);
    create("input2.txt", plants, radiations);
    simulate(plants,radiations,ans,s);
    CHECK(ans.size() == 5);
    ans.clear();
    destroyplants(plants);
    create("input3.txt", plants, radiations);
    simulate(plants,radiations,ans,s);
    CHECK(ans.size() == 5);
    ans.clear();
    destroyplants(plants);
    create("input4.txt", plants, radiations);
    simulate(plants,radiations,ans,s);
    CHECK(ans.size() == 5);
    ans.clear();
    destroyplants(plants);

    destroyradiation();
}
TEST_CASE("2", "2nd") {

    vector<radiation*> radiations;
    vector<Plants*> plants;
     vector <Plants*> ans;
     bool s = false;

    create("input.txt", plants, radiations);
    simulate(plants,radiations,ans,s);
    CHECK(plants[3]->alive() == false);
    destroyplants(plants);

    create("input2.txt", plants, radiations);
    simulate(plants,radiations,ans,s);
    CHECK(plants[3]->alive() == true);
    destroyplants(plants);

    create("input4.txt", plants, radiations);
    simulate(plants,radiations,ans,s);
    CHECK(plants[0]->alive() == true);
    destroyplants(plants);

    create("input3.txt", plants, radiations);
    simulate(plants,radiations,ans,s);
    CHECK(plants[4]->alive() == true);
    destroyplants(plants);

    destroyradiation();

}

TEST_CASE("3", "3rd") {

    vector<radiation*> radiations;
    vector<Plants*> plants;
    vector <Plants*> ans;
    bool s = false;

    create("input.txt", plants, radiations);
    simulate(plants,radiations,ans,s);
    CHECK(plants[0]->getPower() == 8);
    CHECK(plants[1]->getPower() == 1);
    CHECK(plants[2]->getPower() == 4);
    destroyplants(plants);

    create("input2.txt", plants, radiations);
    simulate(plants,radiations,ans,s);
    CHECK(plants[0]->getPower() == 5);
    CHECK(plants[1]->getPower() == 3);
    CHECK(plants[2]->getPower() == 4);
    CHECK(plants[3]->getPower() == 2);
    CHECK(plants[4]->getPower() == 7);
    destroyplants(plants);

    create("input3.txt", plants, radiations);
    simulate(plants,radiations,ans,s);
    CHECK(plants[0]->getPower() == 8);
    CHECK(plants[1]->getPower() == 1);
    CHECK(plants[2]->getPower() == 4);
    CHECK(plants[3]->getPower() == 5);
    destroyplants(plants);

    destroyradiation();

}

TEST_CASE("4", "4th") {

    vector<radiation*> radiations;
    vector<Plants*> plants;
    vector <Plants*> ans;
    bool s = false;

    create("input.txt", plants, radiations);
    simulate(plants,radiations,ans,s);
    CHECK(plants[0]->name() == "Hungry");
    CHECK(plants[1]->name() == "Lanky");
    CHECK(plants[2]->name() == "Big");
    destroyplants(plants);

    create("input2.txt", plants, radiations);
    simulate(plants,radiations,ans,s);
    CHECK(plants[0]->name() == "Rose");
    CHECK(plants[1]->name() == "Lilly");
    CHECK(plants[2]->name() == "Jasmine");
    CHECK(plants[3]->name() == "Gold");
    CHECK(plants[4]->name() == "Silver");
    destroyplants(plants);

    destroyradiation();

}

#endif // NORMAL_M














//void compute (vector<Plants*> &plants,vector<radiation*>radiations,int j)
//{
//        reqAlpha = 0 , reqDelta = 0;
//        for (unsigned int i = 0; i < plants.size(); i++) // summing up the alpha and delta demand
//        {
//            if(plants[i]->alive())
//            {
//                reqAlpha+= plants[i]->getAlpha();
//                reqDelta+= plants[i]->getDelta();
//            }
//        }
//
//            if(reqAlpha >= (3+reqDelta))
//                {
//                    radiations[j+1] =  Alpha::instance();
//                }
//            else if(reqDelta >= (3+reqAlpha))
//                {
//                    radiations[j+1] =  Delta::instance();
//                }
//            else
//                {
//                    radiations[j+1] = No_radiation::instance();
//                }
//}








//#include <iostream>
//#include <cstdlib>
//#include <fstream>
//#include <vector>
//#include "radiation.h"
//#include "creature.h"
//#include <exception>
//
//using namespace std;
//
//void create(const string &str, vector<Plants*> &plants, vector<radiation*> &radiations)
//{
//    ifstream f(str);
//    if(f.fail()) { cout << "Wrong file name!\n"; exit(1);}
//
//    int n; f >> n;
//    plants.resize(n);
//    radiations.clear();
//    radiations.push_back(No_radiation::instance());
//
//    for(int i=0;i<n;++i)
//     {
//         string plantName, plantType; int plantLevel;
//         f >> plantName >> plantType >> plantLevel;
//
//         if(plantType == "wom")
//         {
//              plants[i] = new Wombleroot(plantName,plantLevel);
//         }
//         else if(plantType == "wit")
//         {
//             plants[i] = new Wittenroot(plantName,plantLevel);
//         }
//         else if(plantType == "wor")
//         {
//             plants[i] = new Woreroot(plantName,plantLevel);
//         }
//
//     }
//}
//
//
//// destroying plants
//void destroyplants(vector<Plants*> &plants)
//{
//    for(unsigned int i=0;i<plants.size(); i++) delete plants[i];
//}
//
////destroying radiations
//void destroyradiation()
//{
//    No_radiation::destroy();
//    Alpha::destroy();
//    Delta::destroy();
//}
//
//void simulate (vector<Plants*> &plants, vector<radiation*> &radiations, vector <Plants*> &ans)
//{
//    try
//    {
//
//    int j = 0;
//
//    bool l = false;
//    int reqAlpha;
//    int reqDelta;
//    string rad = "No Radiation";
//    while (true)
//    {
// //           cout<<"#############################################################"<<endl;
//            cout<<endl;
//            cout<<"Day "<<j+1<<endl;
////            cout<<"Radiation of the day is " << rad << endl ;
//            cout<<endl;
//        if (l && radiations[j] == No_radiation::instance())
//        {
//            cout << "Two Consecutive days founded with No Radiations " << endl;
//            break;
//        }
//         if( radiations[j] == No_radiation::instance() )
//         {
//             l = true;
//         }
//        reqAlpha = 0 , reqDelta = 0;
//        for (unsigned int i = 0; i < plants.size(); i++) // summing up the alpha and delta demand
//        {
//            if(plants[i]->alive())
//            {
//                reqAlpha+= plants[i]->getAlpha();
//                reqDelta+= plants[i]->getDelta();
//            }
//        }
//
//            if(reqAlpha >= (3+reqDelta))
//                {
//                    radiations[j+1] =  Alpha::instance();
//                    rad = "Alpha";
//                }
//            else if(reqDelta >= (3+reqAlpha))
//                {
//                    radiations[j+1] =  Delta::instance();
//                    rad = "Delta";
//                }
//            else
//                {
//                    radiations[j+1] = No_radiation::instance();
//                    rad = "No Radiation";
//                }
//
//         for(unsigned int k=0;k < plants.size();k++)
//        {
//  //          cout<<"size"<<plants.size()<<endl;
//
//           if(plants[k]->alive())
//            {
//            plants[k]->influence(radiations[j]);
//            cout << "====================================================" << endl;
//            cout << "Name of the plant is " << plants[k]->name() << endl;
//             if(plants[k]->alive())
//            {
//                cout << plants[k]->name() <<" is alive"<<endl;
//                cout << "Energy level " << plants[k]->getPower() << endl;
//            }
//            else
//            {
//                cout << plants[k]->name() <<" is dead"<<endl;
//
//                plants.erase(plants.begin()+k);
//                k -= 1;
//            }
//
//            }
//        }
// //       cout<<"\n \nRadiation of next day will be " << rad << endl ;
////        cout<<"#############################################################"<<endl<<endl<<endl<<endl;
//
//        j++;
//
//    }
//     for(unsigned int i = 0; i < plants.size(); i++)
//     {
//         ans.push_back(plants[i]);
//     }
//  }
//  catch (exception e)
//  {
//      cout<<e.what();
//  }
//}
//
//
//#define NORMAL_MODE
//#ifdef NORMAL_MODE
//
//int main()
//{
//    vector<Plants*> plants;
//
//    vector<Plants*> ans;
//    ans.clear();
//    vector<radiation*> radiations;
//    create("input8.txt",plants,radiations);
//
//    simulate(plants,radiations,ans);
////    cout<<endl<<endl<<endl;
////    for(unsigned int i = 0; i < ans.size();i++)
////    {
////        cout << "Name of the plant is " << plants[i]->name() << endl;
////             if(plants[i]->alive())
////            {
////                cout << plants[i]->name() <<" is alive"<<endl;
////                cout << "Energy level " << plants[i]->getPower() << endl;
////            }
////            else
////            {
////                cout << plants[i]->name() <<" is dead"<<endl;
////            }
////    }
//       destroyplants(plants);
//       destroyradiation();
//
//    return 0;
//}
//
//#else
//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"
//
//
//
//TEST_CASE("1", "input2.txt")
//{
//    vector<radiation*> radiations;
//    vector<Plants*> plants;
//    vector <Plants*> ans;
//
//    create("input.txt", plants, radiations);
//    simulate(plants,radiations,ans);
//    CHECK(ans.size() == 3);
//    ans.clear();
//    destroyplants(plants);
//
//    create("input2.txt", plants, radiations);
//    simulate(plants,radiations,ans);
//    CHECK(ans.size() == 5);
//    ans.clear();
//    destroyplants(plants);
//
//    create("input3.txt", plants, radiations);
//    simulate(plants,radiations,ans);
//    CHECK(ans.size() == 5);
//    ans.clear();
//    destroyplants(plants);
//
//    create("input4.txt", plants, radiations);
//    simulate(plants,radiations,ans);
//    CHECK(ans.size() == 5);
//    ans.clear();
//   destroyplants(plants);
////
////    create("input7.txt", plants, radiations);
////    simulate(plants,radiations,ans);
////    CHECK(ans.size() == 2);
////    ans.clear();
////    destroyplants(plants);
////
////    create("input8.txt", plants, radiations);
////    simulate(plants,radiations,ans);
////    CHECK(ans.size() == 3);
////    //ans.clear();
////    destroyplants(plants);
////
//
//
//    destroyradiation();
//}
//
////TEST_CASE("2", "2nd") {
////
////    vector<radiation*> radiations;
////    vector<Plants*> plants;
////    vector < vector <Plants*> >ans;
////
////    create("input.txt", plants, radiations);
////    simulate(plants,radiations,ans);
////    CHECK(plants[3]->alive() == false);
////    destroyplants(plants);
////
////    create("input2.txt", plants, radiations);
////    simulate(plants,radiations,ans);
////    CHECK(plants[3]->alive() == true);
////    destroyplants(plants);
////
////    create("input4.txt", plants, radiations);
////    simulate(plants,radiations,ans);
////    CHECK(plants[0]->alive() == true);
////    destroyplants(plants);
////
////    create("input3.txt", plants, radiations);
////    simulate(plants,radiations,ans);
////    CHECK(plants[4]->alive() == false);
////    destroyplants(plants);
////
////    destroyradiation();
////
////}
////// plants[k]->getPower()
////
////TEST_CASE("3", "3rd") {
////
////    vector<radiation*> radiations;
////    vector<Plants*> plants;
////    vector < vector <Plants*> >ans;
////
////    create("input.txt", plants, radiations);
////    simulate(plants,radiations,ans);
////    CHECK(plants[2]->getPower() == 4);
////    destroyplants(plants);
////
////    create("input2.txt", plants, radiations);
////    simulate(plants,radiations,ans);
////    CHECK(plants[3]->getPower() == 2);
////    destroyplants(plants);
////
////    create("input4.txt", plants, radiations);
////    simulate(plants,radiations,ans);
////    CHECK(plants[0]->getPower() == 6);
////    destroyplants(plants);
////
////    destroyradiation();
////
////}
////
////
//#endif // NORMAL_M
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
//
//
//
////void compute (vector<Plants*> &plants,vector<radiation*>radiations,int j)
////{
////        reqAlpha = 0 , reqDelta = 0;
////        for (unsigned int i = 0; i < plants.size(); i++) // summing up the alpha and delta demand
////        {
////            if(plants[i]->alive())
////            {
////                reqAlpha+= plants[i]->getAlpha();
////                reqDelta+= plants[i]->getDelta();
////            }
////        }
////
////            if(reqAlpha >= (3+reqDelta))
////                {
////                    radiations[j+1] =  Alpha::instance();
////                }
////            else if(reqDelta >= (3+reqAlpha))
////                {
////                    radiations[j+1] =  Delta::instance();
////                }
////            else
////                {
////                    radiations[j+1] = No_radiation::instance();
////                }
////}
//
