#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <array>
#include "animals.h"
#include <vector>
#include "mammals.h"
#include "reptiles.h"
#include "lions.h"
#include "zones.h"

// Khai báo vector để chứa các động vật
std::vector<Lion> lions;
std::vector<Animal> animal;
std ::vector<Zone> zones;
FILE *outputFile = fopen("output.txt", "w");

void initlion()
{
    for (int i = 0; i < 5; i++)
    {
        // Khởi tạo giá trị của Lion qua Constructer Lion
        Lion B = Lion("Whispering Woods", 2, 100, 100, 90, 80, 77, 89, 80, 90, 90, "Forest", 45, true, false, 0);
        // Thêm Lion mới được khởi tạo vào vector
        lions.push_back(B);
    }
}

void initZones()
{
    // Khởi tạo zone
    Zone a = Zone("Whispering Woods", "Forest", 350, 305, "Rock");
    Zone b = Zone("Savannah Safari", "Grassland", 400, 50, "Mound");
    Zone c = Zone("Sunbaked Sands", "Desert", 150, 20, "Sand Dune");
    Zone d = Zone("Lagoon Landing", "Wetlands", 200, 30, "Log");
    Zone e = Zone("Coral Cove", "Coastal", 500, 90, "Rock");
    // Thêm zone vào vector zones
    zones.push_back(a);
    zones.push_back(b);
    zones.push_back(c);
    zones.push_back(d);
    zones.push_back(e);
}

void check_habitat_for_lion()
{
    // Tạo 1 biến để gán giá trị current_habitat
    std::string current_habitat;
    for (int i = 0; i < zones.size(); i++)
    {
        // So sánh zone name với zone hiện tại mà sư tử đang sống(mặc định all lion sống ở cùng 1 khu vực 
        //nên lấy lions[0] làm đại diện)
        if (zones[i].name == lions[i].getzone())
        {
            //Nếu đã tìm được thì gán current_habitat bằng Habitat trong zone vừa tìm được
            current_habitat = zones[i].habitat;
        }
    }
    // Lặp để tất cả lions đều được sử dụng phương thức checkHabitat
    for (int i = 0; i < lions.size(); i++)
    {
        //truyền biến tương ứng vào phương thức
        lions[i].checkHabitat(current_habitat, lions[i].getHabitat());
    }
}
void printLions()
{
    for (int i = 0; i < lions.size(); i++)
    {
        //In ra ngoài file
        fprintf(outputFile, "#%d\t\t\t\t\t%.2f\t\t\t\t\t%.2f\t\t\t\t\t%.2f\t\t\t\t\t%.2f\t\t\t\t\t%.2f\t\t\t\t\t%.2f\t\t\t\t\t%.2f\t\t\t\t\t%.2f\n",
                i + 1, lions[i].gethealth(), lions[i].getwell_being(), lions[i].gethunger(), lions[i].gethydration(), lions[i].getenergy(), lions[i].getsocial(), lions[i].getmental_stim(), lions[i].getcomfort());
    }
}
void checklife()
{
    // Lặp để tất cả lions đều được sử dụng phương thức checkLife
    for (int i = 0; i < lions.size(); i++)
    {
        if (lions[i].check_life() == false)
        {
            // Nếu lion die thì xóa lion hiện tại ra khỏi vector lions
            lions.erase(lions.begin() + i);
            //trừ i đi 1 đơn vị vì sau khi xóa 1 phần tử tại vị trí i thì tất cả các phần tử tại vị trí 
            //sau i sẽ bị đẩy lên trước 1 đơn vị( mục đích là để lấp vào vị trí vừa bị xóa)
            i--;
        }
    }
}
void checkteritory()
{
    //cái này tương tự check_habitat_for_lion nhé
    double zone_size;
    for (int i = 0; i < zones.size(); i++)
    {
        if (zones[i].name == lions[i].getzone())
        {
            zone_size = zones[i].size;
        }
    }

    for (int i = 0; i < lions.size(); i++)
    {

        lions[i].checkterritory(zone_size / lions.size());
    }
}
void actionforlion()
{
    //Gọi các hàm để lần lượt thực thi các phương thức tương ứng
    check_habitat_for_lion();
    checkteritory();
    checklife();
}
void One_moth()
{
    //lấy số lượng sư tử hiện tại
    int cnt_lion = lions.size();
    actionforlion();
    //sau khi gọi actionforlion thì sẽ có 1 vài con chết, hàm dưới đây để liệt kê lion đã chết
    for (int i = 0; i < cnt_lion - lions.size(); i++)
    {
        //Xuất ra file
        fprintf(outputFile, "%d Lion Death\n", i);
    }
}
int main()
{
    //Khởi tạo lion
    initlion();
    //khởi tạo zone
    initZones();
    //in các thuộc tính của lion
    printLions();
    //Thực thi hàm One_month
    One_moth();
    //In lion sau 1 tháng
    printLions();
    return 0;
}