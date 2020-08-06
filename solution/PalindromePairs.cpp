  #include<vector>
  #include<string>
  #include<iostream>
  using namespace std;
  //暴力超时
//   bool testIsPalin(string s){
//       if(s=="")
//       return false;
//       int l =s.length();
//       for(int i=0;i<l/2;i++){
//         if(s.at(i)!=s.at(l-1-i))
//             return false;
//          }
      
//       return true;
      
//   }
//   vector<vector<int>> palindromePairs(vector<string>& words) {
//       vector<vector<int>> v;
//       int s =words.size();
//       string tmp ="";
//       for(int i=0;i<s;i++){
//           for(int j =0;j<s;j++){
//               if(i==j)
//               continue;
//               tmp= words[i]+words[j];
//               if(testIsPalin(tmp)){
//                   vector<int> n={i,j};
//                   v.push_back(n);
//               }
//           }
//       }
//       return v;
//     }

int main(){
    vector<string> s={"deeabafjjegeajaajjc","head","bg","gfjadiheadidhb","ejhadfdbbf","gfgjjcheijghhbgi","bd","gj","faebidibahheheajhdad","cgfbbijhchgiagdjg","heegfahdei","afajcfbgbjcehjbajgch","fhdgf","fhfbidiehbd","acicifaaiaeda","egdcghfgiede","ihj","aieegchdhjggbaf","ahfaea","bfjjaei","iiahcdbddhhabhfa","fhdhifbhfijfjdhhaec","jjcaab","fgejaeicgcdb","ijeifhfaagbbhbgd","djgbh","bchbghbdhj","ihibdbede","aaieeg","bedidgaijhjffi","cii","bbfiehhaejhaihg","ebcfedjifefhaaich","dbhaebibchdai","gaeeabjeeefeba","feaiahffifhbjbjc","aibficccdgebha","caijihcaijbjdgh","fa","jajdhdgciciabf","jggijggefe","hieagiifgeiggcbda","hbdjhccf","bcifgjid","abidejifhfgagcbj","eie","dhgfcadbgi","ggbdadafdgdjaijbff","aafbefjjich","hhgjffdbhjjce","dccacijd","edaabga","jghcciedjeheecafjafi","hajhfbeade","ai","chehhhjbadd","higihhbia","h","daaffhigihffgib","hdchgcjfhehbdchjbfee","iehahgbd","hhbbhecee","hicchaicbcdcbghgbcb","ggehfjiacca","bicbj","iddagad","egjjajjfijicddghgjbd","fgdj","fdhadabhegefhiaaffj","jjdgd","jigefcbhfbah","fegif","edacai","chchigjif","ihdc","iichejea","ifeahhec","iicb","chhgjifbidccjh","jdbhjffj","dgghdhdhgjh","ggijbj","hac","gabch","acge","ihjdi","afbefigffcgg","jcdghaegagffiaa","fchbdbfgdgihgcbbf","afhehifegdggai","dhejd","bcdjaid","bfhacfgifgfbeiiadbj","cbjaiafefbiaha","fjdggbbdjfhggggi","adadhijfeddcfhcffcf","eebfbhjcfebfbiiii","bddjcheg","bbhbccagghhccbcadii","jjbdjhbi","aadicc","igigjecd","aigg","headbfabhi","aggf","gdibgfgdjf","ddejhdgaie","feigiedidjafibiiabeg","ihejc","dbhjdgceiajac","jgaddec","decf","jeahifda","ei","ceicjagifdajdaggbei","jdfegeagefjjd","ffjgej","abigcgfegii","cbia","ddbccgeiicad","ddjcedidfehhggjifcdc","djahchfjiaabcdfcghc","jd","egfhjgcdabgbijiaif","ebfagijiec","e","i","fdjechdehbg","hibdd","gcdcajhiiahgjebdef","cgebjdfeficigcbajeeg","fegihdbbgceeieja","fcfdeadbfgbg","idgb","feej","caefiaadhaeedfahjjg","gcjhgjajdjbacadiab","ceeahgafc","giidhhaedbhi","gfi","hggigegffeedd","bjaajbdecc","dcegegdigidghbfg","gdaehaagehc","ebcfe","hbihiaehibajbh","dd","chbddebaffaechfiafe","jgdabdhbae","ejffgfdehicgadjaada","ifih","ad","djjdifjgjjhdiaajefae","dfjabaihc","bdbgeefihdc","eijcghaccghehjheiife","hbd","ejhfehagcfdjfjc","gfiejeeeihfhhdfbga","agjiidgihh","gfhfhghccfjjd","ajg","jefebffddehjdgbjhece","jfgbecahdgheeeigbbbd","gcjgeaefb","geacffib","fbabhiag","hcdhdjh","eegaef","cbgd","fajjfgfeafbicic","cfcec","cjidg","c","becfafc","ceaifhebjcihifchccge","acjgbfb","eehfcdibhhdeaahghg","iajh","eh","dcbfgafj","fjfccjjd","jhgiga","cgddbjigg","ifdfhgddebjbhbdebceg","ghaaddiabgc","hhebbhcedi","gjji","hgjaaicfecdbhiaeeejf","ahdfechfgacaadgb","hegdcfffeghfbdaiah","jadegiij","behdhffcedh","jfagjgjabfggdebbgfbj","cffi","ggchfb","gf","afj","gdajgfjdeehcihbcbfc","bha","aifihgjehhji","jhbhagdcbebgedjib","dddgbcdfgcbcfh","bdcccdfiifaigg","eegbjdad","bijfhidcc","jfgdcbgbeidfbich","diacigecbeagij","ae","jeffgeccdjdfhchbfghb","eedjaejjaefdjbgae","jbj","hfajiiadb","ebce","difedbfejcaj","chbg","feidai","gjeihhc","afcbcdi","cgbhhaeahgh","eacejccfigche","iacbfjjag","iibhcgeidba","acjeie","cjejadcdiiiiie","jf","bdaegihihadedjbfjja","bheaefhedifefgcj","gjhehj","igbcedd","iiaebdgegiagi","jghjeghabfba","bddehbggjbgghbc","fbiidhjjg","jgdhhef","djbdcbciijbife","iaiajhjih","gbjcebdacaeg","ijbjjaahedhibjacjid","hfehjb","bfjejdfjedgbdccch","gcie","jbaahgidgbdbcjgccc","hgffjhgagabgdbjij","ecefhcgebh","da","acaajajfahf","gcghhjbiedghj","becgfjdbeicaiihfh","aadhhcjebagabeicjbdh","ieaahaej","g","hfeijjhfbidhbif","efbgbejjhiifbb","ajj","ciabaaadiagfjeaegg","jehcgdbbcdhc","d","fjeefeaffjj","edhb","jdg","bebacedgbjfdf","bhbfbdh","f","ebghcfdjgfdefjdffgdj","hecbeihfhehbgefhc","eibdacjdbha","jfehaibbagj","igaebgbdbjaehegjgdf","cjaiacffcjfadaahjgib","biajafegbgeeagafb","hgdgjcjigjgajfc","icebffehbfbdfb","aiibhdffaiebih","fgiffg","beffciih","eejibbd","dffhajefgibdbhcgjc","jbjbdaide","ihjfg","iga","ficacgiibich","chjehcgdaehb","gjibc","afigghidejad","heghbeddc","iib","dedbec","igdiaachjibbi","jjbdbbdifabdj","hegegcfbchedebgehg","bedhjddaiefgbjhgacb","eefiff","ijgebgdbii","cjffegfdcibgg","dggcacegag","jecaaed","ijffabbe","hhbfgbcaaifbdfii","dbiffejgjhab","bjdi","ibae","fddfacaicjgi","gcccjgdc","ejgbdddacidiejhf","fbebihdgagdcbibd","bdaef","eibbagafbjjcecb","eiihbggfddhaiabjbfb","hgheehaajggfjaij","cjhieife","cajabidhg","fdg","fgch","deggbid","dcbeaehjjige","hhbfjaifgd","geci","ahhfjfdihjjjceabedab","ibghbfdgfebfgdch","deaaachf","eic","dcdd","fgcjiciebcghgdejfj","igiiadcfdfcfiegfiaci","a","j","ciiaggebcdcfgejcjf","jibicii","cae","ejbg","dccagjaadceggh","dbd","hcjicggcjjfgebfgfdee","cjfcbiahajhb","edifbfhhjdaidhg","bhccbajifabehecaibhf","fidjjhecih","ehi","fibgg","hjeibehifibichbibeg","dbeacjdebe","egcg","hedadiidgacfhgh","jfccgcfhfajjbg","fbejjabchbbdcidfce","jb","ificfdf","afhdfefiedhfc","hidc","iaiafehddcg","fifijfjhhddeceeid","ghdecdfdbhdaf","aabafccbdiebjeffg","fhgeagdibbfab","igaighcjfaeffdeg","hfjijbfedbabebiebgd","bibbdbagibbhge","ghgcccdddijeafdbha","fdhfjfbfjhhhiahaeh","hhdbfdechadjbihd","bbaaabbihgc","fdddcgegcfjbdcfeidh","dggich","ebjgcff","fj","cha","ebajffdbj","efeiddggjdidadib","acbjbbah","addeaeaedh","eiehdjdiji","ffcgcghfeeg","eccjeheedecjiihhhj","gejhfcda","abj","fbbcfghghheabej","ijdiegbf","fg","fjgcgecgahhjhh","bcece","jhjidbjddeec","jfjfjfgefhh","eaggijiahffdihc","cfaaciegcefghd","afddbedfg","bigeagdicegh","djedccg","gaeeea","bajegadgii","ejibciihdeabdjbhai","eabhjieafedibcijbjg","aajggcigfhbhj","ccgjah","hfdih","ebgdgcfbeacgf","iibeehje","ibeeedjgdhbidaefa","bidjcijieeh","dahbeaajfeiidgi","dea","ggjigagch","fb","dghh","dbiefbihaieiaffbadc","gdhhf","hfeaicjeecfibhb","jbdahgghge","ebje","edhfbihhgegbhbfbidhh","bejdjjcj","bdjffgjdef","jchgidcff","edhccejjfbchiiabga","cegafghbdbaceiiaab","gddedgeefg","ieff","fgcddedaijahijcab","gichdibdhddh","gabfagfhd","jcfigahdchjaed","ic","dhhcfaajbabaij","hdgdjdce","djhg","eejfbcajhheaghbdaddf","jbajah","chjf","aaij","gagdhiiiacaiagib","hghdea","fedjiiahgiegbaiaibj","ahchacd","cacbddaafgee","cbfahb","fijfjbiecjc","ieddfiahjfaefcdhih","checfbejdhehjeaeaghh","gbiigiajehbghegaideg","bgh"};
    vector<vector<int>> res=palindromePairs(s);
    cout<<res[0][0];
    return 0;
}