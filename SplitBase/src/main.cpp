#include<ctime>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<cstdlib>
#include<iostream>

int main(int argc,char *argv[]){
  
  std::vector<std::string> classes;
  classes.push_back("Apuleia");
  classes.push_back("Aspidosperma");
  classes.push_back("Astronium");
  classes.push_back("Byrsonima");
  classes.push_back("Calophyllum");
  classes.push_back("Cecropia");
  classes.push_back("Cedrelinga");
  classes.push_back("Cochlospermum");
  classes.push_back("Combretum");
  classes.push_back("Copaifera");

  std::ofstream train_file("training.txt");
  std::ofstream val_file("validation.txt");
 
  if(!train_file.is_open() || !val_file.is_open()){
    std::cout << "\33[1;31mCould not open one or both output files!!!\33[0m"
              << std::endl;
    return -1;
  }
  std::srand(std::time(NULL)); 
  for(unsigned int i = 0; i < classes.size(); ++i){
    for(unsigned int j = 0; j < 7; ++j){
      for(unsigned int k = 0; k < 40; ++k){
        std::string image_name;
        if(k < 10){
          image_name = classes[i] + "_00" + std::to_string(j)
                                  + "_00" + std::to_string(k) + ".tif";
        } else {
          image_name = classes[i] + "_00" + std::to_string(j)
                                  +  "_0" + std::to_string(k) + ".tif";
        }
       
        int n = std::rand() % 10 + 1;
        std::cout << n << std::endl;
        if(n <= 6){
          train_file << image_name + " " + classes[i] + "\n";
        } else {
          val_file << image_name + " " + classes[i] + "\n";
        }            
      }
    }
  }
  train_file.close();
  val_file.close();  
  return 0;
}
