# ESOE-Programming
Homework of ESOE programming class

## Final Report of Sorting 資料夾架構及說明
![img](https://github.com/Aaron-Hsieh-0129/ESOE-Programming/blob/main/架構圖.png)

-----------   

### bin/Sorting 執行方式（推薦直接執行bin/底下的shell script）
##### usage1 (Self-Defined Data): *./Sorting -[Score|ID|FirstName|LastName] -[SS|IS|BS|HS] -[random|increasing|decreasing|semi] <size> <output_file>*  
##### Ex1: *./Sorting -Score -SS -random 1000 ../outputs/output.txt*  

##### usage2 (Normal Data): *./Sorting -[SS|IS|BS|HS] <input_file> <output_fule>*  
##### Ex2: *./Sorting -SS ../generated_data/data_normal_generated/10_int_random.txt ../outputs/10_int_random.txt*  
  
-----------   
  
### bin/ComplexDataGenerate 執行方式（推薦直接執行bin/底下的shell script）
##### usage: *./DataGenerate <data number>*  
##### Ex: *./DataGenerate 1000*

-----------   
  
### bin/NormalDataGenerate 執行方式（推薦直接執行bin/底下的shell script）
##### usage: *./NormalDataGenerate <data number> <output>*  
##### Ex: *./NormalDataGenerate 1000 ../generated_data/data_normal_generated/1000*
