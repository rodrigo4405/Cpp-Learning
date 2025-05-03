#include <iostream>
#include <vector>

const int MAX_ITEMS = 10;

class Row {
private:
    std::vector<double> items = {};

public: 
    std::string row_name = "";
    
    Row(std::string name) {
        row_name = name;
    }

    void add_item(double item) {
        items.push_back(item);
    }

    std::vector<double> get_items(void) {
        return items;
    }
};

class Table {
private:
    std::vector<Row> rows = {};

public:
    std::string table_name = "";

    Table(std::string name) {
        table_name = name; 
    }

    void add_row(Row row) {
        rows.push_back(row);
    }

    std::vector<Row> get_rows(void) {
        return rows;
    }

    
};


int main(void) {
    Table mainTable("Table");
    Row varRow("xi");

    mainTable.add_row(varRow);

    std::string itm;
    int num;
    for (int i = 1; i <= 10; i++) {
        std::cout << "\rItem #" << i << ": ";
        std::cin >> itm;

        if (itm.empty()) { break; }

        try {
            num = std::stoi(itm);
        } catch (const std::invalid_argument& e) {
            std::cerr << "NaN\n";
            break;

        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            break;
        }

        varRow.add_item(num);
    }
}