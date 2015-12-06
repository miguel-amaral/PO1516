
echo -n -e "/* -------------- */\n" > final.cpp;
echo -n -e "/*  TextItem.cpp  */\n" >> final.cpp;
echo -n -e "/* -------------- */\n" >>final.cpp;
cat TextItem.cpp >> final.cpp;
echo -n -e "\n" >> final.cpp;
                    ###                                   #####
echo -n -e "/* -------------- */\n" >>final.cpp;
echo -n -e "/*  TextSpan.cpp  */\n" >> final.cpp;
echo -n -e "/* -------------- */\n" >>final.cpp;
cat TextSpan.cpp   >> final.cpp;
echo -n -e "\n" >> final.cpp;

echo -n -e "/* -------------- */\n" >>final.cpp;
echo -n -e "/* TextFormat.cpp */\n" >> final.cpp ;
echo -n -e "/* -------------- */\n" >>final.cpp;
cat TextFormat.cpp >> final.cpp;
echo -n -e "\n" >> final.cpp;


echo -n -e "/* -------------- */\n" >>final.cpp;
echo -n -e "/*    Bold.cpp    */\n" >> final.cpp ;
echo -n -e "/* -------------- */\n" >>final.cpp;
cat Bold.cpp       >> final.cpp;
echo -n -e "\n" >> final.cpp;

echo -n -e "/* -------------- */\n" >>final.cpp;
echo -n -e "/*  Underline.cpp */\n" >> final.cpp ;
echo -n -e "/* -------------- */\n" >>final.cpp;
cat Underline.cpp  >> final.cpp;
echo -n -e "\n" >> final.cpp;

echo -n -e "/* -------------- */\n" >>final.cpp;
echo -n -e "/*   Italic.cpp   */\n" >> final.cpp ;
echo -n -e "/* -------------- */\n" >>final.cpp;
cat Italic.cpp     >> final.cpp;
echo -n -e "\n" >> final.cpp;

echo -n -e "/* -------------- */\n" >>final.cpp;
echo -n -e "/*    main.cpp    */\n" >> final.cpp ;
echo -n -e "/* -------------- */\n" >>final.cpp;
cat main.cpp >> final.cpp;

#include "TextSpan.cpp"
#include "TextFormat.cpp"
#include "Bold.cpp"
#include "Underline.cpp"
#include "Italic.cpp"
#include "main.cpp"

cat final.cpp;
