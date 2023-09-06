mkdir -p bin
rm -r ./bin/*

g++ *.cpp -o bin/knn_WI_K3_F.elf -D SCENARIO=WI_K3_F
g++ *.cpp -o bin/knn_WI_K3_D.elf -D SCENARIO=WI_K3_D
g++ *.cpp -o bin/knn_WI_K20_F.elf -D SCENARIO=WI_K20_F
g++ *.cpp -o bin/knn_WI_K20_D.elf -D SCENARIO=WI_K20_D
g++ *.cpp -o bin/knn_GA_K20_F.elf -D SCENARIO=GA_K20_F
g++ *.cpp -o bin/knn_GA_K20_D.elf -D SCENARIO=GA_K20_D
g++ *.cpp -o bin/knn_GB_K20_F.elf -D SCENARIO=GB_K20_F
g++ *.cpp -o bin/knn_GB_K20_D.elf -D SCENARIO=GB_K20_D

echo "------------------------------------------------"
./bin/knn_WI_K3_F.elf
echo "------------------------------------------------"
./bin/knn_WI_K3_D.elf
echo "------------------------------------------------"
./bin/knn_WI_K20_F.elf
echo "------------------------------------------------"
./bin/knn_WI_K20_D.elf
echo "------------------------------------------------"
./bin/knn_GA_K20_F.elf
echo "------------------------------------------------"
./bin/knn_GA_K20_D.elf
echo "------------------------------------------------"
./bin/knn_GB_K20_F.elf
echo "------------------------------------------------"
./bin/knn_GB_K20_D.elf
echo "------------------------------------------------"