/*
 * OOPS Project submitted by:
 *
 * Team-3 (A2 Batch)
 *
 * Name:            USN:                Roll No:
 * Abdul Razzak     01fe19bcs048        143
 * Archit Kumar     01fe19bcs044        139
 * Shlok Jha        01fe19bcs046        141
 */
#include<bits/stdc++.h>
using namespace std;
//--------------------------------------- - Allottees - ----------------------------------------------------------------

class invalid_credentials_provided{
    string error_message="\nxxxx x Invalid credentials provided: invalid_credentials_provided() exception thrown x xxxx\n";
public:
    void display_error(){
        cout<<error_message<<"\n";
    }
};
class access_denied{
private:
    string error_message="\nxxxx x Wrong password: access_denied() exception thrown x xxxx\n";
public:
    void display_error(){
        cout<<error_message<<"\n";
    }
};
class invalid_input{
private:
    string error_message="\nxxxx x Invalid input provided: invalid_input() exception thrown x xxxx\n";
public:
    void display_error(){
        cout<<error_message<<"\n";
    }
};
class access_granted{
private:
    string error_message="\nxxxx x Access granted! x xxxx\n";
public:
    void display_error(){
        cout<<error_message<<"\n";
    }
};
//
class Allottees{
public:
    string name;
    string dob;
    string usn;     //usn must be in strict numericals
    string gender;
    //
    virtual ~Allottees(){}
    //
    virtual void get_allottee()=0;
    virtual void set_allottee(string,string)=0;
};
class Female_allottee:public Allottees{
public:
    Female_allottee(){}
    Female_allottee(string name,string dob,string usn){
        this->name=name;
        try {
            if(stoi(dob) != 0) {
                this->dob = dob;
            }
            else throw dob;
        }
        catch(string dob_val){
            cout<<"Invalid dob supplied!\n";
        }
        this->usn=usn;
        this->gender="Female";
    }
    //
    virtual void get_allottee()override{
        cout<<"Name: "<<name<<"\n";
        cout<<"Date of Birth: "<<dob<<"\n";
        cout<<"Gender: "<<gender<<"\n";
        cout<<"University Roll Number: "<<usn<<"\n";
    }
    virtual void set_allottee(string parameter_select,string parameter_val)override{
        if(parameter_select == "name"){
            this->name=parameter_val;
        }
        else if(parameter_select == "dob"){
            this->dob=parameter_val;
        }
        else if(parameter_select == "usn"){
            this->usn=parameter_val;
        }
    }
};
class Male_allottee:public Allottees{
public:
    Male_allottee(){}
    Male_allottee(string name,string dob,string usn){
        this->name=name;
        this->dob=dob;
        this->usn=usn;
        this->gender="Male";
    }
    //
    virtual void get_allottee()override{
        cout<<"Name: "<<name<<"\n";
        cout<<"Date of Birth: "<<dob<<"\n";
        cout<<"Gender: "<<gender<<"\n";
        cout<<"University Roll Number: "<<usn<<"\n";
    }
    virtual void set_allottee(string parameter_select,string parameter_val)override{
        if(parameter_select == "name"){
            this->name=parameter_val;
        }
        else if(parameter_select == "dob"){
            this->dob=parameter_val;
        }
        else if(parameter_select == "usn"){
            this->usn=parameter_val;
        }
    }
};

//------------------------------------------------- - Rooms - ----------------------------------------------------------

class Rooms{
public:
    string room_no;
    string type;

    //
    virtual void get_room()=0;
    //virtual void set_room()=0;
    //
    virtual void vacate_room()=0;
    virtual void vacate_allottee(int)=0;
    virtual void add_allottee(Allottees *)=0;
    virtual bool is_empty_slot()=0;
    //
    virtual ~Rooms(){};
};
class Double_sharing:public Rooms{
public:
    map<int,Allottees*> occupants;
    //
    Double_sharing(){}
    Double_sharing(string room_no){
        this->room_no=room_no;
        this->type="Double_Sharing";
    }
    //
    virtual void get_room() override{
        cout<<"Room no: "<<room_no<<endl;
        cout<<"Room type: "<<type<<endl;
        cout<<"Occupant info:\n";
        for(auto itr=occupants.begin();itr!=occupants.end();itr++){
            cout<<"Occupant id: "<<(*itr).first<<"\n";
            (*itr).second->get_allottee();
            cout<<endl;
        }
    }
    //
    virtual void vacate_room() override{
        this->occupants.clear();
        cout<<"Room vacated successfully!\n";
    }
    virtual void vacate_allottee(int allottee_id) override{
        occupants.erase(occupants.find(allottee_id));
        cout<<"Allottee with the id: "<<allottee_id<<" has vacated the room!\n";
    }
    virtual void add_allottee(Allottees* new_allottee) override{
        if(occupants.size()>=3){
            cout<<"Room no. "<<room_no<<" has no vacancy!\n";
        }
        else{
            occupants.insert(make_pair(stoi(new_allottee->usn),new_allottee));
        }
    }
    virtual bool is_empty_slot() override{
        return occupants.size()<2 ? true : false;
    }
};
class Triple_sharing:public Rooms{
public:
    Triple_sharing(){}
    Triple_sharing(string room_no){
        this->room_no=room_no;
        type="triple sharing";
    }
    map<int,Allottees*> occupants;
    //
    virtual void get_room() override{
        cout<<"Room no: "<<room_no<<endl;
        cout<<"Room type: "<<type<<endl;
        cout<<"Occupant info:\n";
        for(auto itr=occupants.begin();itr!=occupants.end();itr++){
            cout<<"Occupant id: "<<(*itr).first<<"\n";
            (*itr).second->get_allottee();
            cout<<endl;
        }
    }
    //
    virtual void vacate_room() override{
        this->occupants.clear();
        cout<<"Room vacated successfully!\n";
    }
    virtual void vacate_allottee(int allottee_id) override{
        occupants.erase(occupants.find(allottee_id));
        cout<<"Allottee with the id: "<<allottee_id<<" has vacated the room!\n";
    }
    virtual void add_allottee(Allottees* new_allottee) override{
        if(occupants.size()>=3){
            cout<<"Room no. "<<room_no<<" has no vacancy!\n";
        }
        else{
            occupants.insert(make_pair(stoi(new_allottee->usn),new_allottee));
        }
    }
    virtual bool is_empty_slot() override{
        return occupants.size()<3 ? true : false;
    }
};

//=========================================== = Login and error exception = ============================================
class admin_login{
private:
    string user_id={"admin"};
    string password={"passwd"};
protected:
    string user_id_input;
    string password_input;
public:
    bool flag;
    void login_prompt() {
        try {
            cout << "Enter user id:\n";
            cin >> user_id_input;
            cout << "Password:\n";
            cin >> password_input;
            if(user_id_input==user_id && password_input==password){
                throw access_granted();
            }
            else{
                throw invalid_credentials_provided();
            }
        }
        catch (access_granted acc){
            acc.display_error();
            cout<<"\nWelcome!!!\n";
            cout<<"\nloading the system. . . . .\n";
            flag=true;
        }
        catch (invalid_credentials_provided inv){
            inv.display_error();
            cout<<"\nYou have entered invalid user id or password. . .\n";
            cout<<"\n!!!ACCESS DENIED!!!\n";
            flag=false;
        }
    }
    void modify_login_credentials(string user_id,string password){
        this->user_id=user_id;
        this->password=password;
        cout<<"\nChanges done successfully!\n";
    }
    bool sudo_validate_pass(string password){
        return (this->password==password);
    }
};
class sudo_mode:public admin_login{
public:
    void display(){
        cout<<"\nCaution you are in super_user_mode, any change(s) done will be irrevertible!\n";
    }
    void update_login_credentials(){
        string new_user_id,new_password;
        cout<<"\nEnter new user id and password, respectively:\n";
        cin>>new_user_id>>new_password;
        modify_login_credentials(new_user_id,new_password);
    }
    bool validate(){
        string admin_pass;
        cout<<"\nEnter current administrator password again, to gain super user privileges!\n";
        cin>>admin_pass;
        if(sudo_validate_pass(admin_pass)){
            return true;
        }
        else{
            return false;
        }
    }
};
//------------------------------------------------ - Menue - ---------------------------------------------------------
class Menue{
public:
    map<int,string> veg_menue;
    map<int,string> non_veg_menue;
    //
    Menue(){}
    Menue(map<int,string> veg_menue,map<int,string> non_veg_menue){
        this->veg_menue=veg_menue;
        this->non_veg_menue=non_veg_menue;
    }
    //
    void get_veg_menue(){
        cout<<"Veg Menue items: \n";
        for(auto itr=veg_menue.begin();itr!=veg_menue.end();itr++){
            cout<<(*itr).first<<" "<<(*itr).second<<endl;
        }
    }
    void get_non_veg_menue(){
        cout<<"Non-veg Menue items: \n";
        for(auto itr=veg_menue.begin();itr!=veg_menue.end();itr++){
            cout<<(*itr).first<<" "<<(*itr).second<<endl;
        }
    }
    //
    void update_veg_menue(int item_no,string new_item){
        //veg_menue.at(item_no)=new_item;
        veg_menue.erase(item_no);
        veg_menue.insert(make_pair(item_no,new_item));
    }
    void update_non_veg_menue(int item_no,string new_item){
        //non_veg_menue.at(item_no)=new_item;
        non_veg_menue.erase(item_no);
        non_veg_menue.insert(make_pair(item_no,new_item));
    }
};
//------------------------------------------------- - Mess - ---------------------------------------------------------
class Mess{
public:
    string name;
    string type;
    map<int,string> staff_list;
    Menue* menue_items;
    //
    int mess_fees;
    //
    virtual void get_mess()=0;
    virtual void get_mess_menue()=0;
    virtual void update_menue_item(int,string)=0;
    virtual void update_staff(int,string)=0;
    //
    virtual void set_fees(int)=0;
    virtual void get_fees()=0;
    //
    virtual ~Mess(){}
};
class Veg_mess:public Mess{
public:
    //
    Veg_mess(){}
    Veg_mess(string name,map<int,string> staff_list,Menue* menue_items){
        this->name=name;
        this->type="Vegetarian";
        this->staff_list=staff_list;
        this->menue_items=menue_items;
        mess_fees=30000;
    }
    //
    virtual void get_mess() override{
        cout<<"Mess name: "<<name<<"\n";
        cout<<"Mess type: "<<type<<"\n";
        cout<<"Staff list: \n";
        for(auto itr=staff_list.begin();itr!=staff_list.end();itr++){
            cout<<(*itr).first<<"   "<<(*itr).second<<endl;
        }
        menue_items->get_veg_menue();
    }
    virtual void get_mess_menue() override{
        menue_items->get_veg_menue();
    }
    virtual void update_menue_item(int item_no,string new_item) override{
        menue_items->veg_menue.insert(make_pair(item_no,new_item));
    }
    virtual void update_staff(int staff_id,string name) override{
        staff_list.insert(make_pair(staff_id,name));
    }
    //
    virtual void get_fees() override{
        cout<<mess_fees<<"\n";
    }
    virtual void set_fees(int mess_fees) override{
        this->mess_fees=mess_fees;
    }
};
class Non_veg_mess:public Mess{
public:
    //
    Non_veg_mess(){}
    Non_veg_mess(string name,map<int,string> staff_list,Menue* menue_items){
        this->name=name;
        this->type="Non-vegetarian";
        this->staff_list=staff_list;
        this->menue_items=menue_items;
        mess_fees=60000;
    }
    //
    virtual void get_mess() override{
        cout<<"Mess name: "<<name<<"\n";
        cout<<"Mess type: "<<type<<"\n";
        cout<<"Staff list: \n";
        for(auto itr=staff_list.begin();itr!=staff_list.end();itr++){
            cout<<(*itr).first<<"   "<<(*itr).second<<endl;
        }
        menue_items->get_non_veg_menue();
    }
    virtual void get_mess_menue() override{
        menue_items->get_non_veg_menue();
    }
    virtual void update_menue_item(int item_no,string new_item) override{
        menue_items->non_veg_menue.insert(make_pair(item_no,new_item));
    }
    virtual void update_staff(int staff_id,string name) override{
        staff_list.insert(make_pair(staff_id,name));
    }
    //
    virtual void get_fees() override{
        cout<<mess_fees<<"\n";
    }
    virtual void set_fees(int mess_fees) override{
        this->mess_fees=mess_fees;
    }
};
//
class Hostel{
public:
    string name;
    string type;
    string warden_name;
    string warden_contact_no;
    vector<Rooms* >room_list;
    Mess* mess_veg;
    Mess* mess_non_veg;
    //
    int hostel_fees;
    //
    virtual void get_hostel()=0;
    virtual void get_hostel_staff()=0;
    virtual void get_room_occupants()=0;
    virtual void get_mess_info()=0;
    //
    virtual void get_fees()=0;
    virtual void set_fees(int)=0;
    //
    virtual void set_new_warden(string,string)=0;
    //
    virtual ~Hostel(){}
};
class Boys_hostel:public Hostel{
public:
    Boys_hostel(){}
    Boys_hostel(string name,string warden_name,string warden_contact_no,vector<Rooms*> room_list,Mess* mess_veg,Mess* mess_non_veg){
        this->name=name;
        this->type="Boys Hostel";
        this->warden_name=warden_name;
        this->warden_contact_no=warden_contact_no;
        this->room_list=room_list;
        this->mess_veg=mess_veg;
        this->mess_non_veg=mess_non_veg;
        hostel_fees=45000;
    }
    //
    virtual void get_hostel() override{
        cout<<"Hostel name: "<<name<<endl;
        cout<<"Type: "<<type<<endl;
        cout<<"Warden name: "<<warden_name<<endl;
        cout<<"Warden Contact No.: "<<warden_contact_no<<endl;
        cout<<"Room list: \n";
        for(auto itr=room_list.begin();itr!=room_list.end();itr++){
            (*itr)->get_room();
        }
        //cout<<"Mess info.: \n";
        //mess_veg->get_mess();
        //mess_non_veg->get_mess();
    }
    virtual void get_hostel_staff() override{
        cout<<"Warden: "<<warden_name<<endl;
        cout<<"Hostel Staff: "<<endl;
        for(auto itr=((mess_veg->staff_list).begin());itr!=((mess_veg->staff_list).end());itr++) {
            cout<<(*itr).first<<" "<<(*itr).second<<"\n";
        }
    }
    virtual void get_room_occupants() override{
        for(auto itr=room_list.begin();itr!=room_list.end();itr++) {
            (*itr)->get_room();
        }
    }
    virtual void get_mess_info() override{
        mess_veg->get_mess();
        mess_non_veg->get_mess();
    }
    virtual void get_fees()override{
        cout<<this->hostel_fees<<"\n";
    }
    virtual void set_fees(int hostel_fees) override{
        this->hostel_fees=hostel_fees;
    }
    //

    virtual void set_new_warden(string warden_name,string warden_contact_no) override{
        this->warden_name=warden_name;
        this->warden_contact_no=warden_contact_no;
    }
};
class Girls_hostel:public Hostel{
public:
    Girls_hostel(){}
    Girls_hostel(string name,string warden_name,string warden_contact_no,vector<Rooms*> room_list,Mess* mess_veg,Mess* mess_non_veg){
        this->name=name;
        this->type="Girls Hostel";
        this->warden_name=warden_name;
        this->warden_contact_no=warden_contact_no;
        this->room_list=room_list;
        mess_veg->get_mess();
        mess_non_veg->get_mess();
        hostel_fees=450000;
    }
    //
    virtual void get_hostel() override{
        cout<<"Hostel name: "<<name<<endl;
        cout<<"Type: "<<type<<endl;
        cout<<"Warden name: "<<warden_name<<endl;
        cout<<"Warden Contact No.: "<<warden_contact_no<<endl;
        cout<<"Room list: \n";
        for(auto itr=room_list.begin();itr!=room_list.end();itr++){
            (*itr)->get_room();
        }
        // cout<<"Mess info.: \n";
        //mess_veg->get_mess();
        //mess_non_veg->get_mess();
    }
    virtual void get_hostel_staff() override{
        cout<<"Warden: "<<warden_name<<endl;
        cout<<"Hostel Staff: "<<endl;
        for(auto itr=((mess_veg->staff_list).begin());itr!=((mess_veg->staff_list).end());itr++) {
            cout<<(*itr).first<<" "<<(*itr).second<<"\n";
        }
    }
    virtual void get_room_occupants() override{
        for(auto itr=room_list.begin();itr!=room_list.end();itr++) {
            (*itr)->get_room();
        }
    }
    virtual void get_mess_info() override{
        mess_veg->get_mess();
        mess_non_veg->get_mess();
    }
    //
    virtual void get_fees()override{
        cout<<this->hostel_fees<<"\n";
    }
    virtual void set_fees(int hostel_fees) override{
        this->hostel_fees=hostel_fees;
    }
    //

    virtual void set_new_warden(string warden_name,string warden_contact_no) override{
        this->warden_name=warden_name;
        this->warden_contact_no=warden_contact_no;
    }
};
//------------------------------------------------- - Driver Code - --------------------------------------------------
int main(){
    vector<Allottees *> allottee_list_male;
    vector<Allottees *> allottee_list_female;
    allottee_list_female.push_back(new Female_allottee("A","27/03/2001","06601"));
    allottee_list_female.push_back(new Female_allottee("B","17/01/2003","06602"));
    allottee_list_female.push_back(new Female_allottee("C","27/05/2001","06603"));
    allottee_list_female.push_back(new Female_allottee("D","23/06/2003","06604"));
    allottee_list_female.push_back(new Female_allottee("E","7/12/2001","06605"));
    allottee_list_female.push_back(new Female_allottee("F","3/11/2003","06606"));
    allottee_list_female.push_back(new Female_allottee("G","17/10/2001","06607"));
    allottee_list_female.push_back(new Female_allottee("H","2/09/2003","06608"));
    allottee_list_female.push_back(new Female_allottee("I","7/06/2001","06609"));
    allottee_list_female.push_back(new Female_allottee("J","5/07/2003","06610"));

    allottee_list_male.push_back(new Male_allottee("a","27/03/2001","06611"));
    allottee_list_male.push_back(new Male_allottee("b","17/01/2003","06612"));
    allottee_list_male.push_back(new Male_allottee("c","27/05/2001","06613"));
    allottee_list_male.push_back(new Male_allottee("d","23/06/2003","06614"));
    allottee_list_male.push_back(new Male_allottee("e","7/12/2001","06615"));
    allottee_list_male.push_back(new Male_allottee("f","3/11/2003","06616"));
    allottee_list_male.push_back(new Male_allottee("g","17/10/2001","06617"));
    allottee_list_male.push_back(new Male_allottee("h","2/09/2003","06618"));
    allottee_list_male.push_back(new Male_allottee("h","7/06/2001","06619"));
    allottee_list_male.push_back(new Male_allottee("i","5/07/2003","06620"));

    //
    vector<Rooms *> double_rooms_list_girls;
    vector<Rooms *> double_rooms_list_boys;
    vector<Rooms *> triple_rooms_list_girls;
    vector<Rooms *> triple_rooms_list_boys;
    for(int i=101;i<110;i++){
        double_rooms_list_boys.push_back(new Double_sharing(to_string(i)));
        double_rooms_list_girls.push_back(new Double_sharing(to_string(i)));
    }
    for(int i=201;i<210;i++){
        triple_rooms_list_boys.push_back(new Triple_sharing(to_string(i)));
        triple_rooms_list_girls.push_back(new Triple_sharing(to_string(i)));
    }
//
    map<int,string> menue_val_veg;
    map<int,string> menue_val_non_veg;
    menue_val_veg.insert(make_pair(1,"Oatmeal"));
    menue_val_veg.insert(make_pair(2,"Butter Paneer"));
    menue_val_veg.insert(make_pair(3,"Malai Kofta"));
    menue_val_veg.insert(make_pair(4,"Mix Veg"));
    menue_val_veg.insert(make_pair(5,"Mushroom chilli"));
    menue_val_veg.insert(make_pair(6,"Aloo Sabzi"));
    menue_val_veg.insert(make_pair(7,"Dal Makhni"));
    menue_val_veg.insert(make_pair(8,"Mix Dal"));
    menue_val_veg.insert(make_pair(9,"Raita"));
    menue_val_veg.insert(make_pair(10,"Tawa Roti"));
    menue_val_veg.insert(make_pair(11,"Rice"));

    menue_val_non_veg.insert(make_pair(1,"Omelette"));
    menue_val_non_veg.insert(make_pair(2,"Chicken Curry"));
    menue_val_non_veg.insert(make_pair(3,"Murg Makhni"));
    menue_val_non_veg.insert(make_pair(4,"Mughlai Chicken"));
    menue_val_non_veg.insert(make_pair(5,"Fillet-o-Fish"));
    menue_val_non_veg.insert(make_pair(6,"Prawn Gravy"));
    menue_val_non_veg.insert(make_pair(7,"Mutton Masala"));
    menue_val_non_veg.insert(make_pair(8,"Boiled Egg"));
    menue_val_non_veg.insert(make_pair(9,"Egg Curry"));
    menue_val_non_veg.insert(make_pair(10,"Butter Roti"));
    menue_val_non_veg.insert(make_pair(11,"Roti"));
    menue_val_non_veg.insert(make_pair(12,"Chicken Biryani"));
    menue_val_non_veg.insert(make_pair(13,"Rice"));
    //
    Menue* menue;
    menue=new Menue(menue_val_veg,menue_val_non_veg);
    //
    map<int,string> staff;

    staff.insert(make_pair(7701,"Priyanka"));
    staff.insert(make_pair(7702,"Sridevi"));
    staff.insert(make_pair(7703,"Sheila"));
    staff.insert(make_pair(7704,"Rajkumari"));
    staff.insert(make_pair(7705,"Sheetal"));
    staff.insert(make_pair(7706,"Aishwarya"));
    staff.insert(make_pair(7707,"Seema"));
    staff.insert(make_pair(7708,"Sanya"));
    staff.insert(make_pair(7709,"Sania"));
    staff.insert(make_pair(7710,"Simran"));

    staff.insert(make_pair(8801,"Basavaraj"));
    staff.insert(make_pair(8802,"Rajkumar"));
    staff.insert(make_pair(8803,"Rakesh"));
    staff.insert(make_pair(8804,"Suman"));
    staff.insert(make_pair(8805,"Rohit"));
    staff.insert(make_pair(8806,"Sunil"));
    staff.insert(make_pair(8807,"Virat"));
    staff.insert(make_pair(8808,"Jadeja"));
    staff.insert(make_pair(8809,"Rishabh"));
    staff.insert(make_pair(8810,"Prithvi"));

    //
    Mess* mess_veg=new Veg_mess("Central Veg Mess",staff,menue);
    Mess* mess_non_veg=new Non_veg_mess("Central NonVeg Mess",staff,menue);
    //
    Hostel* girls_hostel_double_sharing=new Girls_hostel("Vindhya Double Sharing Quaters","Vindya","9000000089",double_rooms_list_girls,mess_veg,mess_non_veg);
    Hostel* boys_hostel_double_sharing=new Boys_hostel("Betta Double Sharing Quaters","Basavaraj","7800000089",double_rooms_list_boys,mess_veg,mess_non_veg);
    Hostel* girls_hostel_triple_sharing=new Girls_hostel("Vindhya Triple Sharing Quaters","Bindya","9000000088",triple_rooms_list_girls,mess_veg,mess_non_veg);
    Hostel* boys_hostel_triple_sharing=new Boys_hostel("Betta Triple Sharing Quaters","Swamy","8000000088",triple_rooms_list_boys,mess_veg,mess_non_veg);

    //Pre filling some allottees in the room
    int counter_male=0,counter_female=0;
    for(auto itr=boys_hostel_double_sharing->room_list.begin();itr!=boys_hostel_double_sharing->room_list.begin()+5;itr++){
        if((*itr)->is_empty_slot()){
            (*itr)->add_allottee(allottee_list_male.at(counter_male));
            counter_male++;
        }
        else continue;
    }
    for(auto itr=girls_hostel_double_sharing->room_list.begin();itr!=girls_hostel_double_sharing->room_list.begin()+5;itr++){
        if((*itr)->is_empty_slot()){
            (*itr)->add_allottee(allottee_list_female.at(counter_female));
            counter_female++;
        }
        else continue;
    }
    for(auto itr=boys_hostel_triple_sharing->room_list.begin();itr!=boys_hostel_triple_sharing->room_list.begin()+5;itr++){
        if((*itr)->is_empty_slot()){
            (*itr)->add_allottee(allottee_list_male.at(counter_male));
            counter_male++;
        }
        else continue;
    }
    for(auto itr=girls_hostel_triple_sharing->room_list.begin();itr!=girls_hostel_triple_sharing->room_list.begin()+5;itr++){
        if((*itr)->is_empty_slot()){
            (*itr)->add_allottee(allottee_list_male.at(counter_female));
            counter_female++;
        }
        else continue;
    }
    //

    //cout<<"\n\nGirls hostel info:\n\n";
    //girls_hostel_double_sharing->get_hostel();
    //girls_hostel_triple_sharing->get_hostel();
    //cout<<"\n===============================\n";
    //cout<<"\n\nBoys hostel info:\n\n";
    //boys_hostel_double_sharing->get_hostel();
    //boys_hostel_triple_sharing->get_hostel();
//=========================================================================================================
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    while(1) {
        admin_login login;
        cout<<"\n************** * * Administrator login page * * ******************\n";
        login.login_prompt();
        cout<<"\n---------------- - ------------------- - -----------\n";
        if (login.flag) {
            //===================================================================================================
            do {
                cout
                        << "\n\n\n========================================================================================\n\n\n";
                cout << "Driver menue:";
                cout
                        << "\n\n\n========================================================================================\n\n\n";
                cout << "Welcome to Hostel services management system!" << endl;
                cout << "1.Add a new allottee\n";
                cout << "2.Vacate a Room\n";
                cout << "3.Vacate a room occupant\n";
                cout << "4.Update Hostel Staff\n";
                cout << "5.Update Mess Menue\n";
                cout << "6.Get room info\n";
                cout << "7.Get mess info\n";
                cout << "8.Get staff info\n";
                cout << "9.Update Hostel fees\n";
                cout << "10.Update Mess Fees\n";
                cout << "11.Change Warden\n";
                cout << "12.log out\n\n";

                cout << "* * 99.Change Administrator login id and password (Super-user privileges required)* *\n\n";

                int opt;
                cin >> opt;
                switch (opt) {
                    //girls_hostel_double_sharing->get_hostel();
                    case 1: {
                        cout << "Enter name, Date of birth(DD/MM/YYYY),usn and gender(male/female) of the allottee: \n";
                        string name, dob, usn, gender, room_type;
                        cin >> name >> dob >> usn >> gender;
                        try {
                            if (gender == "male") {
                                Allottees *new_allottee_male = new Male_allottee(name, dob, usn);
                                cout << "Enter the type of room(double/triple) allottee wants:\n";
                                cin >> room_type;
                                try {
                                    if (room_type == "double") {
                                        auto itr = double_rooms_list_boys.begin();
                                        while (itr != double_rooms_list_boys.end()) {
                                            if ((*itr)->is_empty_slot()) {
                                                (*itr)->add_allottee(new_allottee_male);
                                                break;
                                            }
                                            itr++;
                                        }
                                    } else if (room_type == "triple") {
                                        auto itr = triple_rooms_list_boys.begin();
                                        while (itr != triple_rooms_list_boys.end()) {
                                            if ((*itr)->is_empty_slot()) {
                                                (*itr)->add_allottee(new_allottee_male);
                                                break;
                                            }
                                            itr++;
                                        }
                                    } else {
                                        throw invalid_input();
                                    }
                                }
                                catch (invalid_input inp) {
                                    inp.display_error();
                                    cout << "\n@@@@ @ Invalid option entered! @ @@@@\n";
                                }
                            } else if (gender == "female") {
                                Allottees *new_allottee_female = new Female_allottee(name, dob, usn);
                                cout << "Enter the type of room(double/triple) allottee wants:\n";
                                cin >> room_type;
                                try {
                                    if (room_type == "double") {
                                        auto itr = double_rooms_list_girls.begin();
                                        while (itr != double_rooms_list_girls.end()) {
                                            if ((*itr)->is_empty_slot()) {
                                                (*itr)->add_allottee(new_allottee_female);
                                                break;
                                            }
                                            itr++;
                                        }
                                    } else if (room_type == "triple") {
                                        auto itr = triple_rooms_list_girls.begin();
                                        while (itr != triple_rooms_list_girls.end()) {
                                            if ((*itr)->is_empty_slot()) {
                                                (*itr)->add_allottee(new_allottee_female);
                                                break;
                                            }
                                            itr++;
                                        }
                                    } else {
                                        throw invalid_input();
                                    }
                                }
                                catch (invalid_input inp) {
                                    inp.display_error();
                                    cout << "\n@@@@ @ Invalid option entered! @ @@@@\n";
                                }
                            }else{
                                throw invalid_input();
                            }
                        }
                        catch(invalid_input inp){
                            inp.display_error();
                            cout<<"\n@@@@ @ Invalid option entered! @ @@@@\n";
                        }
                        //girls_hostel_double_sharing->get_hostel();
                    }
                        break;
                    case 2: {
                        cout << "Choose hostel:\n";
                        cout<< "1.Double sharing boys quaters\n2.Double sharing girls quaters\n3.Triple sharing boys quaters\n4.Triple sharing girls quater\n";
                        int hostel_choice;
                        cin >> hostel_choice;
                        try {
                            if (hostel_choice == 1) {
                                cout << "Enter the room number you want to vacate:\n";
                                int room_choice;
                                cin >> room_choice;
                                for (auto itr = double_rooms_list_boys.begin();
                                     itr != double_rooms_list_boys.end(); itr++) {
                                    if (stoi((*itr)->room_no) == room_choice) {
                                        (*itr)->vacate_room();
                                        cout << "Room no. " << room_choice << " has been vacated successfully!";
                                    }
                                }
                            } else if (hostel_choice == 2) {
                                cout << "Enter the room number you want to vacate:\n";
                                int room_choice;
                                cin >> room_choice;
                                for (auto itr = double_rooms_list_girls.begin();
                                     itr != double_rooms_list_girls.end(); itr++) {
                                    if (stoi((*itr)->room_no) == room_choice) {
                                        (*itr)->vacate_room();
                                        cout << "Room no. " << room_choice << " has been vacated successfully!";
                                    }
                                }
                            } else if (hostel_choice == 3) {
                                cout << "Enter the room number you want to vacate:\n";
                                int room_choice;
                                cin >> room_choice;
                                for (auto itr = triple_rooms_list_boys.begin();
                                     itr != triple_rooms_list_boys.end(); itr++) {
                                    if (stoi((*itr)->room_no) == room_choice) {
                                        (*itr)->vacate_room();
                                        cout << "Room no. " << room_choice << " has been vacated successfully!";
                                    }
                                }
                            } else if (hostel_choice == 4) {
                                cout << "Enter the room number you want to vacate:\n";
                                int room_choice;
                                cin >> room_choice;
                                for (auto itr = triple_rooms_list_girls.begin();
                                     itr != triple_rooms_list_girls.end(); itr++) {
                                    if (stoi((*itr)->room_no) == room_choice) {
                                        (*itr)->vacate_room();
                                        cout << "Room no. " << room_choice << " has been vacated successfully!";
                                    }
                                }
                            }else{
                                throw invalid_input();
                            }
                        }
                        catch(invalid_input inp){
                            inp.display_error();
                            cout<<"\n@@@@ @ Invalid option entered! @ @@@@\n";
                        }
                    }
                        break;
                    case 3: {
                        cout<< "Choose a hostel:\n1. Double Sharing boy's quater\n2.Double sharing girl's quater\n3.Triple sharing boy's quater\n4.Triple sharing girl's quater\n";
                        int hostel_option;
                        cin >> hostel_option;
                        try {
                            if (hostel_option == 1) {
                                cout << "Enter occupant's room number and usn, to remove records:\n";
                                string usn_val;
                                int room_no_val;
                                cin >> room_no_val;
                                cin >> usn_val;

                                for (auto itr = double_rooms_list_boys.begin();
                                     itr != double_rooms_list_boys.end(); itr++) {
                                    if (stoi((*itr)->room_no) == room_no_val) {
                                        (*itr)->vacate_allottee(stoi(usn_val));
                                    }
                                }
                            } else if (hostel_option == 2) {
                                cout << "Enter occupant's room number and usn, to remove records:\n";
                                string usn_val;
                                int room_no_val;
                                cin >> room_no_val;
                                cin >> usn_val;

                                for (auto itr = double_rooms_list_girls.begin();
                                     itr != double_rooms_list_girls.end(); itr++) {
                                    if (stoi((*itr)->room_no) == room_no_val) {
                                        (*itr)->vacate_allottee(stoi(usn_val));
                                    }
                                }
                            } else if (hostel_option == 3) {
                                cout << "Enter occupant's room number and usn, to remove records:\n";
                                string usn_val;
                                int room_no_val;
                                cin >> room_no_val;
                                cin >> usn_val;

                                for (auto itr = triple_rooms_list_boys.begin();
                                     itr != triple_rooms_list_boys.end(); itr++) {
                                    if (stoi((*itr)->room_no) == room_no_val) {
                                        (*itr)->vacate_allottee(stoi(usn_val));
                                    }
                                }
                            } else if (hostel_option == 4) {
                                cout << "Enter occupant's room number and usn, to remove records:\n";
                                string usn_val;
                                int room_no_val;
                                cin >> room_no_val;
                                cin >> usn_val;

                                for (auto itr = triple_rooms_list_girls.begin();
                                     itr != triple_rooms_list_girls.end(); itr++) {
                                    if (stoi((*itr)->room_no) == room_no_val) {
                                        (*itr)->vacate_allottee(stoi(usn_val));
                                    }
                                }
                            }else{
                                throw invalid_input();
                            }
                        }
                        catch(invalid_input inp){
                            inp.display_error();
                            cout<<"\n@@@@ @ Invalid option entered! @ @@@@\n";
                        }
                    }
                        break;
                    case 4: {
                        cout << "Choose an action:\n 1.Add a staff\n2.Remove a staff\n";
                        int opt;
                        cin >> opt;
                        try {
                            if (opt == 1) {
                                int new_id;
                                string new_staff;
                                cout << "Enter new staff's id and name:\n";
                                cin >> new_id >> new_staff;
                                staff.insert(make_pair(new_id, new_staff));
                            } else if (opt == 2) {
                                int find_id;
                                //string new_staff;
                                cout << "Enter staff's id to delete the record:\n";
                                cin >> find_id;
                                staff.erase(find_id);
                            }else{
                                throw invalid_input();
                            }
                        }
                        catch(invalid_input inp){
                            inp.display_error();
                            cout<<"\n@@@@ @ Invalid option entered! @ @@@@\n";
                        }
                    }
                        break;
                    case 5: {
                        cout << "Choose anyone of the following actions:\n1.Replace a menue item\n2.Add a new menue item\n";
                        int opt;
                        cin >> opt;
                        try {
                            if (opt == 1) {
                                cout<< "Press 1 to replace item in veg menue or press 2 to replace an item in non veg menu:\n";
                                int opt;
                                cin >> opt;
                                int item_key;
                                string item_name;
                                cout << "Enter item key and name:\n";
                                cin >> item_key >> item_name;
                                try {
                                    if (opt == 1) {
                                        girls_hostel_double_sharing->mess_veg->update_menue_item(item_key, item_name);
                                        boys_hostel_double_sharing->mess_veg->update_menue_item(item_key, item_name);
                                        girls_hostel_triple_sharing->mess_veg->update_menue_item(item_key, item_name);
                                        boys_hostel_triple_sharing->mess_veg->update_menue_item(item_key, item_name);
                                    } else if (opt == 2) {
                                        girls_hostel_double_sharing->mess_non_veg->update_menue_item(item_key, item_name);
                                        boys_hostel_double_sharing->mess_non_veg->update_menue_item(item_key, item_name);
                                        girls_hostel_triple_sharing->mess_non_veg->update_menue_item(item_key, item_name);
                                        boys_hostel_triple_sharing->mess_non_veg->update_menue_item(item_key, item_name);
                                    } else {
                                        throw invalid_input();
                                    }
                                }
                                catch (invalid_input inp) {
                                    inp.display_error();
                                    cout << "\n@@@@ @ Invalid option entered! @ @@@@\n";
                                }
                            } else if (opt == 2) {
                                cout << "Press 1 to add item in veg menue or press 2 to add an item in non veg menu:\n";
                                int opt;
                                cin >> opt;
                                int item_key;
                                string item_name;
                                cout << "Enter item key and name:\n";
                                cin >> item_key >> item_name;
                                try {
                                    if (opt == 1) {
//                                        girls_hostel_double_sharing->mess_veg->update_menue_item(item_key, item_name);
//                                        boys_hostel_double_sharing->mess_veg->update_menue_item(item_key, item_name);
//                                        girls_hostel_triple_sharing->mess_veg->update_menue_item(item_key, item_name);
//                                        boys_hostel_triple_sharing->mess_veg->update_menue_item(item_key, item_name);
                                        girls_hostel_double_sharing->mess_veg->menue_items->update_veg_menue(item_key,item_name);
                                        boys_hostel_double_sharing->mess_veg->menue_items->update_veg_menue(item_key, item_name);
                                        girls_hostel_triple_sharing->mess_veg->menue_items->update_veg_menue(item_key, item_name);
                                        boys_hostel_triple_sharing->mess_veg->menue_items->update_veg_menue(item_key, item_name);
                                    } else if (opt == 2) {
                                        girls_hostel_double_sharing->mess_non_veg->menue_items->update_non_veg_menue(item_key, item_name);
                                        boys_hostel_double_sharing->mess_non_veg->menue_items->update_non_veg_menue(item_key, item_name);
                                        girls_hostel_triple_sharing->mess_non_veg->menue_items->update_non_veg_menue(item_key, item_name);
                                        boys_hostel_triple_sharing->mess_non_veg->menue_items->update_non_veg_menue(item_key, item_name);
                                    } else {
                                        throw invalid_input();
                                    }
                                }
                                catch (invalid_input inp) {
                                    inp.display_error();
                                    cout << "\n@@@@ @ Invalid option entered! @ @@@@\n";
                                }
                            }else{
                                throw invalid_input();
                            }
                        }
                        catch(invalid_input inp){
                            inp.display_error();
                            cout<<"\n@@@@ @ Invalid option entered! @ @@@@\n";
                        }
                    }
                        break;
                    case 6: {
                        cout << "press 1 to see boys room info or press 2 to see girls room info\n";
                        int room_info_opt;
                        cin >> room_info_opt;
                        try {
                            if (room_info_opt == 1) {
                                cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                                cout << boys_hostel_double_sharing->name;
                                cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                                for (auto itr = boys_hostel_double_sharing->room_list.begin();
                                     itr != boys_hostel_double_sharing->room_list.end(); itr++) {
                                    (*itr)->get_room();
                                }
                                cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                                cout << boys_hostel_triple_sharing->name;
                                cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                                for (auto itr = boys_hostel_triple_sharing->room_list.begin();
                                     itr != boys_hostel_triple_sharing->room_list.end(); itr++) {
                                    (*itr)->get_room();
                                }
                            } else if (room_info_opt == 2) {
                                cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                                cout << girls_hostel_double_sharing->name;
                                cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                                for (auto itr = girls_hostel_double_sharing->room_list.begin();
                                     itr != girls_hostel_double_sharing->room_list.end(); itr++) {
                                    (*itr)->get_room();
                                }
                                cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                                cout << girls_hostel_triple_sharing->name;
                                cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                                for (auto itr = girls_hostel_triple_sharing->room_list.begin();
                                     itr != girls_hostel_triple_sharing->room_list.end(); itr++) {
                                    (*itr)->get_room();
                                }
                            } else {
                                throw invalid_input();
                            }
                        }
                        catch(invalid_input inp){
                            inp.display_error();
                            cout<<"\n@@@@ @ Invalid option entered! @ @@@@\n";
                        }
                    }
                        break;
                    case 7: {
                        cout << "press 1 to see boys mess info or press 2 to see girls mess info\n";
                        int mess_info_opt;
                        cin >> mess_info_opt;
                        try {
                            if (mess_info_opt == 1) {
                                boys_hostel_double_sharing->get_mess_info();
                                boys_hostel_triple_sharing->get_mess_info();
                            } else if (mess_info_opt == 2) {
                                girls_hostel_double_sharing->get_mess_info();
                                girls_hostel_triple_sharing->get_mess_info();
                            }
                            else{
                                throw invalid_input();
                            }
                        }
                        catch(invalid_input inp){
                            inp.display_error();
                            cout<<"\n@@@@ @ Invalid option entered! @ @@@@\n";
                        }
                    }
                        break;
                    case 8: {
                        cout << "\n\n------------Hostel Staff info:------------------------\n\n";
                        cout << "Boys hostel wardens:\n";
                        cout << boys_hostel_double_sharing->warden_name << "\n";
                        cout << "Contact no: ";
                        cout << boys_hostel_double_sharing->warden_contact_no << "\n";
                        cout << boys_hostel_triple_sharing->warden_name << "\n";
                        cout << "Contact no: ";
                        cout << boys_hostel_triple_sharing->warden_contact_no << "\n";
                        cout << "\nGirls hostel wardens:\n";
                        cout << girls_hostel_double_sharing->warden_name << "\n";
                        cout << "Contact no: ";
                        cout << girls_hostel_double_sharing->warden_contact_no << "\n";
                        cout << girls_hostel_triple_sharing->warden_name << "\n";
                        cout << "Contact no: ";
                        cout << girls_hostel_triple_sharing->warden_contact_no << "\n";
                        cout << "\nHotel mess staff ID and name:\n";
                        for (auto itr = staff.begin(); itr != staff.end(); itr++) {
                            cout << (*itr).first << "   " << (*itr).second << "\n";
                        }
                    }
                        break;
                    case 9: {
                        cout << "Which hostel type's fees you want to update(double/triple)?\n";
                        string type_input;
                        cin >> type_input;
                        int new_fees;
                        cout << "\nEnter new fees value:\n";
                        cin >> new_fees;
                        try {
                            if (type_input == "double") {
                                boys_hostel_double_sharing->set_fees(new_fees);
                                girls_hostel_double_sharing->set_fees(new_fees);
                                cout << "\noo Updated! oo\n";
                            } else if (type_input == "triple") {
                                boys_hostel_triple_sharing->set_fees(new_fees);
                                girls_hostel_triple_sharing->set_fees(new_fees);
                                cout << "\noo Updated! oo\n";
                            }else{
                                throw invalid_input();
                            }
                        }
                        catch(invalid_input inp){
                            inp.display_error();
                            cout<<"\n@@@@ @ Invalid option entered! @ @@@@\n";
                        }
                    }
                        break;
                    case 10: {
                        cout << "Which mess type's fees you want to update(veg/non-veg)?\n";
                        string type_input;
                        cin >> type_input;
                        int new_fees;
                        cout << "\nEnter new fees value:\n";
                        cin >> new_fees;
                        if (type_input == "veg") {
                            mess_veg->set_fees(new_fees);
                            mess_veg->get_fees();
                            //boys_hostel_double_sharing->mess_veg->set_fees(new_fees);
                            //girls_hostel_double_sharing->mess_veg->set_fees(new_fees);
                            //boys_hostel_triple_sharing->mess_veg->set_fees(new_fees);
                            //girls_hostel_triple_sharing->mess_veg->set_fees(new_fees);
                            cout << "\noo Updated! oo\n";
                            //    girls_hostel_triple_sharing->mess_veg->get_fees();
                        } else if (type_input == "non-veg") {
                            mess_non_veg->set_fees(new_fees);
                            mess_non_veg->get_fees();
                            //boys_hostel_double_sharing->mess_non_veg->set_fees(new_fees);
                            //girls_hostel_double_sharing->mess_non_veg->set_fees(new_fees);
                            //boys_hostel_triple_sharing->mess_non_veg->set_fees(new_fees);
                            //girls_hostel_triple_sharing->mess_non_veg->set_fees(new_fees);
                            cout << "\noo Updated! oo\n";
                            // boys_hostel_double_sharing->mess_non_veg->get_fees();
                        }
                    }
                        break;
                    case 11: {
                        cout << "Select which hostel's warden you want to change:\n";
                        cout << "1. " << boys_hostel_double_sharing->name << "\n";
                        cout << "2. " << girls_hostel_double_sharing->name << "\n";
                        cout << "3. " << boys_hostel_triple_sharing->name << "\n";
                        cout << "4. " << girls_hostel_triple_sharing->name << "\n";
                        int opt_inp;
                        string new_warden_name, new_warden_contact_no;
                        cin >> opt_inp;
                        try {
                            if (opt_inp == 1) {
                                cout << "\nEnter new warden's name and contact number below:\n";
                                cin >> new_warden_name >> new_warden_contact_no;
                                boys_hostel_double_sharing->set_new_warden(new_warden_name, new_warden_contact_no);
                            } else if (opt_inp == 2) {
                                cout << "\nEnter new warden's name and contact number below:\n";
                                cin >> new_warden_name >> new_warden_contact_no;
                                girls_hostel_double_sharing->set_new_warden(new_warden_name, new_warden_contact_no);
                            } else if (opt_inp == 3) {
                                cout << "\nEnter new warden's name and contact number below:\n";
                                cin >> new_warden_name >> new_warden_contact_no;
                                boys_hostel_triple_sharing->set_new_warden(new_warden_name, new_warden_contact_no);
                            } else if (opt_inp == 4) {
                                cout << "\nEnter new warden's name and contact number below:\n";
                                cin >> new_warden_name >> new_warden_contact_no;
                                girls_hostel_triple_sharing->set_new_warden(new_warden_name, new_warden_contact_no);
                            }else{
                                throw invalid_input();
                            }
                        }
                        catch(invalid_input inp){
                            inp.display_error();
                            cout<<"\n@@@@ @ Invalid option entered! @ @@@@\n";
                        }
                    }
                        break;
                    case 12: {
                        exit(0);
                    }
                        break;
                    case 99:{
                        sudo_mode super_user;
                        try {
                            if (super_user.validate()) {
                                super_user.display();
                                super_user.update_login_credentials();
                            } else {
                                throw access_denied();
                            }
                        }
                        catch(access_denied ad){
                            ad.display_error();
                        }
                    }
                        break;

                    default: cout<<"\n\nYou have entered invalid option, try again!\n\n";
                }
            } while (1);
        }
        else{
            string inp;
            cout<<"Do you want to close the program(yes/no)?\n";
            cin>>inp;
            if(inp=="yes") exit(0);
        }
    }
    return 0;
}