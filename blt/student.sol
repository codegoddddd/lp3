// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;
contract MarksManagementSys
{
    struct Student
    {
        int ID;
        string fname;
        string lname;
        int marks;
    }
    
    address owner;
    int public stdCount = 0;
    mapping(int=>Student) public stdRecords;
    modifier onlyOwner
    {
        require(owner==msg.sender);
        _;
    }



    constructor()
    {
        owner = msg.sender;
    }

    function addNewRecords(int _ID,string memory _fname,string memory _lname,int _marks) public onlyOwner
    {
        stdCount = stdCount+1;
        stdRecords[stdCount] = Student(_ID,_fname,_lname,_marks);
    }
    
    function bonusMarks(int _ID,int _bonus) public onlyOwner
    {
        stdRecords[_ID].marks += _bonus;
    }
}
