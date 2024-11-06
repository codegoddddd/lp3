// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;
contract Bank
{
    int bal;
    constructor()  
    {
        bal=0;
    }
    function getBalance() view public returns(int)
    {
        return bal;
    }
    function withdraw(int amt) public 
    {
        if(bal<amt)
        {
            bal=0;
        }
        else{
            bal = bal-amt;
        }
    }
    function deposit(int amt) public 
    {
        bal = bal+amt;
    }
}
