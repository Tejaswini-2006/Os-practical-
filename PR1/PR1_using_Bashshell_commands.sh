
#!/bin/bash

FILE="addressbook.txt"

while true
do
    echo ""
    echo "----- ADDRESS BOOK -----"
    echo "1. Create Address Book"
    echo "2. View Address Book"
    echo "3. Insert Record"
    echo "4. Delete Record"
    echo "5. Modify Record"
    echo "6. Exit"

    echo "Enter your choice:"
    read ch

    case $ch in

    1)
        > "$FILE"
        echo "Address Book Created Successfully!"
        ;;

    2)
        if [ -f "$FILE" ] && [ -s "$FILE" ]
        then
            cat "$FILE"
        else
            echo "Address Book is Empty!"
        fi
        ;;

    3)
        echo "Enter Name:"
        read name
        echo "Enter Phone:"
        read phone
        echo "Enter Email:"
        read email

        echo "$name $phone $email" >> "$FILE"
        echo "Record Inserted Successfully!"
        ;;

    4)
        echo "Enter Name to Delete:"
        read name

        if [ -f "$FILE" ] && grep -q "^$name " "$FILE"
        then
            grep -v "^$name " "$FILE" > temp.txt
            mv temp.txt "$FILE"
            echo "Record Deleted Successfully!"
        else
            echo "Record Not Found!"
        fi
        ;;

    5)
        echo "Enter Name to Modify:"
        read name

        if [ -f "$FILE" ] && grep -q "^$name " "$FILE"
        then
            echo "Enter New Phone:"
            read phone
            echo "Enter New Email:"
            read email

            grep -v "^$name " "$FILE" > temp.txt
            echo "$name $phone $email" >> temp.txt
            mv temp.txt "$FILE"

            echo "Record Modified Successfully!"
        else
            echo "Record Not Found!"
        fi
        ;;

    6)
        echo "Exiting Address Book..."
        exit
        ;;

    *)
        echo "Invalid Choice!"
        ;;

    esac
done




/*


file commands from creating to exacution 
1) create file: touch pratical1.sh
2) OPen file: nano pratical1.sh
3) write the code 
   -write code
   - press ctrl+o to save
   - enter 
   -press ctrl+x to exit 
4)give executable permission: chmod +x pratical1.sh
5) Execute the program:./pratical1.sh




*/