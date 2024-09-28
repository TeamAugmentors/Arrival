#include<iostream>
using namespace std;
# include "iGraphics.h"
int playerx = 860, playery = 190;
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include "GameBackground.h"
#include "Enemy.h"
#include "fire.h"
#include "Bonus.h"
#include "Firecollision.h"
#include "EnemyCollision.h"
#include "Meteor.h"
#define BOOST_LIMIT 100
#define EARTH_HEALTH 100
#define PLAYER_HEALTH 10
void introChange();
void pchange();
int mposx, mposy;
FILE *fp,*option;
int soundflag = 0;
int score[1000]={0};
char score1[100][100];
int scorePosition = 0;
int optionButton=-2;
bool pause=false;
int scorex = 700,  scorey=700;
char options[8][8];
int optionIndex,counter;
int bossCox = 725, bossCoy = 1080 , bossPosition= 650;
bool intro = true, edestroystate=false , pdestroystate = false,shieldstatus=false;
int intro_counter=0;
int meteorflag = 0;
unsigned long long int scoreplayer=0;
int earthhealth = EARTH_HEALTH, playerhealth = PLAYER_HEALTH, blastno = 0, blastflag = 0;
char score2[1000],earth_health[40];
bool playerDead = false, earthDestroyed = false, blastcondition = false, booster = false, introdestroyed=false,bossstate=false, fireflag= false,kalaenemyfireflag=true,bossfireflag=true;
int FireCounter = 0;
int boostMeter =BOOST_LIMIT;
int kalaenemyflag = 0, kalaenemyflag1 = 0,reduce=1;
int  i = 0, f = 0, state = 0, buttonposx, buttonposy, frame = -1, show=0, gamestart=0,t,f1=0,t1, t2, t3;
int fireInd, eindex=0, pindex=0, iindex=0;
char boostmeter[30],shield1[30],planespeed1[20];
int heatcounter = 0,kalaheatcounter=0;
int shield = 0,planespeed=0,planespeedcnt=0;
bool bossHoriY= true, bossVertX =true;
int bossHorizontal , bossHealth = 240, bossHealthCounter = 0; 
int bossVertical, bossSpeed = 10;
struct kalaenemyfire{
	int kalafirex;
	int kalafirey;
	int kalafirespeed;
}kalafire;
struct bossfire
{
	int bossfirex;
	int bossfirey;
	int bossfirespeed=20;
}bossfire[3],bomb1,bomb2;
char introdestroy[1288][50] = { "Picture//A1//A1 0001.bmp", "Picture//A1//A1 0002.bmp", "Picture//A1//A1 0003.bmp", "Picture//A1//A1 0004.bmp", "Picture//A1//A1 0005.bmp", "Picture//A1//A1 0006.bmp", "Picture//A1//A1 0007.bmp", "Picture//A1//A1 0008.bmp", "Picture//A1//A1 0009.bmp", "Picture//A1//A1 0010.bmp",
"Picture//A1//A1 0011.bmp", "Picture//A1//A1 0012.bmp", "Picture//A1//A1 0013.bmp", "Picture//A1//A1 0014.bmp", "Picture//A1//A1 0015.bmp", "Picture//A1//A1 0016.bmp", "Picture//A1//A1 0017.bmp", "Picture//A1//A1 0018.bmp", "Picture//A1//A1 0019.bmp", "Picture//A1//A1 0020.bmp",
"Picture//A1//A1 0021.bmp", "Picture//A1//A1 0022.bmp", "Picture//A1//A1 0023.bmp", "Picture//A1//A1 0024.bmp", "Picture//A1//A1 0025.bmp", "Picture//A1//A1 0026.bmp", "Picture//A1//A1 0027.bmp", "Picture//A1//A1 0028.bmp", "Picture//A1//A1 0029.bmp", "Picture//A1//A1 0030.bmp",
"Picture//A1//A1 0031.bmp", "Picture//A1//A1 0032.bmp", "Picture//A1//A1 0033.bmp", "Picture//A1//A1 0034.bmp", "Picture//A1//A1 0035.bmp", "Picture//A1//A1 0036.bmp", "Picture//A1//A1 0037.bmp", "Picture//A1//A1 0038.bmp", "Picture//A1//A1 0039.bmp", "Picture//A1//A1 0040.bmp",
"Picture//A1//A1 0041.bmp", "Picture//A1//A1 0042.bmp", "Picture//A1//A1 0043.bmp", "Picture//A1//A1 0044.bmp", "Picture//A1//A1 0045.bmp", "Picture//A1//A1 0046.bmp", "Picture//A1//A1 0047.bmp", "Picture//A1//A1 0048.bmp", "Picture//A1//A1 0049.bmp", "Picture//A1//A1 0050.bmp",
"Picture//A1//A1 0051.bmp", "Picture//A1//A1 0052.bmp", "Picture//A1//A1 0053.bmp", "Picture//A1//A1 0054.bmp", "Picture//A1//A1 0055.bmp", "Picture//A1//A1 0056.bmp", "Picture//A1//A1 0057.bmp", "Picture//A1//A1 0058.bmp", "Picture//A1//A1 0059.bmp", "Picture//A1//A1 0060.bmp",
"Picture//A1//A1 0061.bmp", "Picture//A1//A1 0062.bmp", "Picture//A1//A1 0063.bmp", "Picture//A1//A1 0064.bmp", "Picture//A1//A1 0065.bmp", "Picture//A1//A1 0066.bmp", "Picture//A1//A1 0067.bmp", "Picture//A1//A1 0068.bmp", "Picture//A1//A1 0069.bmp", "Picture//A1//A1 0070.bmp",
"Picture//A1//A1 0071.bmp", "Picture//A1//A1 0072.bmp", "Picture//A1//A1 0073.bmp", "Picture//A1//A1 0074.bmp", "Picture//A1//A1 0075.bmp", "Picture//A1//A1 0076.bmp", "Picture//A1//A1 0077.bmp", "Picture//A1//A1 0078.bmp", "Picture//A1//A1 0079.bmp", "Picture//A1//A1 0080.bmp",
"Picture//A1//A1 0081.bmp", "Picture//A1//A1 0082.bmp", "Picture//A1//A1 0083.bmp", "Picture//A1//A1 0084.bmp", "Picture//A1//A1 0085.bmp", "Picture//A1//A1 0086.bmp", "Picture//A1//A1 0087.bmp", "Picture//A1//A1 0088.bmp", "Picture//A1//A1 0089.bmp", "Picture//A1//A1 0090.bmp",
"Picture//A1//A1 0091.bmp", "Picture//A1//A1 0092.bmp", "Picture//A1//A1 0093.bmp", "Picture//A1//A1 0094.bmp", "Picture//A1//A1 0095.bmp", "Picture//A1//A1 0096.bmp", "Picture//A1//A1 0097.bmp", "Picture//A1//A1 0098.bmp", "Picture//A1//A1 0099.bmp", "Picture//A1//A1 0100.bmp",
"Picture//A1//A1 0101.bmp", "Picture//A1//A1 0102.bmp", "Picture//A1//A1 0103.bmp", "Picture//A1//A1 0104.bmp", "Picture//A1//A1 0105.bmp", "Picture//A1//A1 0106.bmp", "Picture//A1//A1 0107.bmp", "Picture//A1//A1 0108.bmp", "Picture//A1//A1 0109.bmp", "Picture//A1//A1 0110.bmp",
"Picture//A1//A1 0111.bmp", "Picture//A1//A1 0112.bmp", "Picture//A1//A1 0113.bmp", "Picture//A1//A1 0114.bmp", "Picture//A1//A1 0115.bmp", "Picture//A1//A1 0116.bmp", "Picture//A1//A1 0117.bmp", "Picture//A1//A1 0118.bmp", "Picture//A1//A1 0119.bmp", "Picture//A1//A1 0120.bmp",
"Picture//A1//A1 0121.bmp", "Picture//A1//A1 0122.bmp", "Picture//A1//A1 0123.bmp", "Picture//A1//A1 0124.bmp", "Picture//A1//A1 0125.bmp", "Picture//A1//A1 0126.bmp", "Picture//A1//A1 0127.bmp", "Picture//A1//A1 0128.bmp", "Picture//A1//A1 0129.bmp", "Picture//A1//A1 0130.bmp",
"Picture//A1//A1 0131.bmp", "Picture//A1//A1 0132.bmp", "Picture//A1//A1 0133.bmp", "Picture//A1//A1 0134.bmp", "Picture//A1//A1 0135.bmp", "Picture//A1//A1 0136.bmp", "Picture//A1//A1 0137.bmp", "Picture//A1//A1 0138.bmp", "Picture//A1//A1 0139.bmp", "Picture//A1//A1 0140.bmp",
"Picture//A1//A1 0141.bmp", "Picture//A1//A1 0142.bmp", "Picture//A1//A1 0143.bmp", "Picture//A1//A1 0144.bmp", "Picture//A1//A1 0145.bmp", "Picture//A1//A1 0146.bmp", "Picture//A1//A1 0147.bmp", "Picture//A1//A1 0148.bmp", "Picture//A1//A1 0149.bmp", "Picture//A1//A1 0150.bmp",
"Picture//A1//A1 0151.bmp", "Picture//A1//A1 0152.bmp", "Picture//A1//A1 0153.bmp", "Picture//A1//A1 0154.bmp", "Picture//A1//A1 0155.bmp", "Picture//A1//A1 0156.bmp", "Picture//A1//A1 0157.bmp", "Picture//A1//A1 0158.bmp", "Picture//A1//A1 0159.bmp", "Picture//A1//A1 0160.bmp",
"Picture//A1//A1 0161.bmp", "Picture//A1//A1 0162.bmp", "Picture//A1//A1 0163.bmp", "Picture//A1//A1 0164.bmp", "Picture//A1//A1 0165.bmp", "Picture//A1//A1 0166.bmp", "Picture//A1//A1 0167.bmp", "Picture//A1//A1 0168.bmp", "Picture//A1//A1 0169.bmp", "Picture//A1//A1 0170.bmp",
"Picture//A1//A1 0171.bmp", "Picture//A1//A1 0172.bmp", "Picture//A1//A1 0173.bmp", "Picture//A1//A1 0174.bmp", "Picture//A1//A1 0175.bmp", "Picture//A1//A1 0176.bmp", "Picture//A1//A1 0177.bmp", "Picture//A1//A1 0178.bmp", "Picture//A1//A1 0179.bmp", "Picture//A1//A1 0180.bmp",
"Picture//A1//A1 0181.bmp", "Picture//A1//A1 0182.bmp", "Picture//A1//A1 0183.bmp", "Picture//A1//A1 0184.bmp", "Picture//A1//A1 0185.bmp", "Picture//A1//A1 0186.bmp", "Picture//A1//A1 0187.bmp", "Picture//A1//A1 0188.bmp", "Picture//A1//A1 0189.bmp", "Picture//A1//A1 0190.bmp",
"Picture//A1//A1 0191.bmp", "Picture//A1//A1 0192.bmp", "Picture//A1//A1 0193.bmp", "Picture//A1//A1 0194.bmp", "Picture//A1//A1 0195.bmp", "Picture//A1//A1 0196.bmp", "Picture//A1//A1 0197.bmp", "Picture//A1//A1 0198.bmp", "Picture//A1//A1 0199.bmp", "Picture//A1//A1 0200.bmp",
"Picture//A1//A1 0201.bmp", "Picture//A1//A1 0202.bmp", "Picture//A1//A1 0203.bmp", "Picture//A1//A1 0204.bmp", "Picture//A1//A1 0205.bmp", "Picture//A1//A1 0206.bmp", "Picture//A1//A1 0207.bmp", "Picture//A1//A1 0208.bmp", "Picture//A1//A1 0209.bmp", "Picture//A1//A1 0210.bmp",
"Picture//A1//A1 0211.bmp", "Picture//A1//A1 0212.bmp", "Picture//A1//A1 0213.bmp", "Picture//A1//A1 0214.bmp", "Picture//A1//A1 0215.bmp", "Picture//A1//A1 0216.bmp", "Picture//A1//A1 0217.bmp", "Picture//A1//A1 0218.bmp", "Picture//A1//A1 0219.bmp", "Picture//A1//A1 0220.bmp",
"Picture//A1//A1 0221.bmp", "Picture//A1//A1 0222.bmp", "Picture//A1//A1 0223.bmp", "Picture//A1//A1 0224.bmp", "Picture//A1//A1 0225.bmp", "Picture//A1//A1 0226.bmp", "Picture//A1//A1 0227.bmp", "Picture//A1//A1 0228.bmp", "Picture//A1//A1 0229.bmp", "Picture//A1//A1 0230.bmp",
"Picture//A1//A1 0231.bmp", "Picture//A1//A1 0232.bmp", "Picture//A1//A1 0233.bmp", "Picture//A1//A1 0234.bmp", "Picture//A1//A1 0235.bmp", "Picture//A1//A1 0236.bmp", "Picture//A1//A1 0237.bmp", "Picture//A1//A1 0238.bmp", "Picture//A1//A1 0239.bmp", "Picture//A1//A1 0240.bmp",
"Picture//A1//A1 0241.bmp", "Picture//A1//A1 0242.bmp", "Picture//A1//A1 0243.bmp", "Picture//A1//A1 0244.bmp", "Picture//A1//A1 0245.bmp", "Picture//A1//A1 0246.bmp", "Picture//A1//A1 0247.bmp", "Picture//A1//A1 0248.bmp", "Picture//A1//A1 0249.bmp", "Picture//A1//A1 0250.bmp",
"Picture//A1//A1 0251.bmp", "Picture//A1//A1 0252.bmp", "Picture//A1//A1 0253.bmp", "Picture//A1//A1 0254.bmp", "Picture//A1//A1 0255.bmp", "Picture//A1//A1 0256.bmp", "Picture//A1//A1 0257.bmp", "Picture//A1//A1 0258.bmp", "Picture//A1//A1 0259.bmp", "Picture//A1//A1 0260.bmp",
"Picture//A1//A1 0261.bmp", "Picture//A1//A1 0262.bmp", "Picture//A1//A1 0263.bmp", "Picture//A1//A1 0264.bmp", "Picture//A1//A1 0265.bmp", "Picture//A1//A1 0266.bmp", "Picture//A1//A1 0267.bmp", "Picture//A1//A1 0268.bmp", "Picture//A1//A1 0269.bmp", "Picture//A1//A1 0270.bmp",
"Picture//A1//A1 0271.bmp", "Picture//A1//A1 0272.bmp", "Picture//A1//A1 0273.bmp", "Picture//A1//A1 0274.bmp", "Picture//A1//A1 0275.bmp", "Picture//A1//A1 0276.bmp", "Picture//A1//A1 0277.bmp", "Picture//A1//A1 0278.bmp", "Picture//A1//A1 0279.bmp", "Picture//A1//A1 0280.bmp",
"Picture//A1//A1 0281.bmp", "Picture//A1//A1 0282.bmp", "Picture//A1//A1 0283.bmp", "Picture//A1//A1 0284.bmp", "Picture//A1//A1 0285.bmp", "Picture//A1//A1 0286.bmp", "Picture//A1//A1 0287.bmp", "Picture//A1//A1 0288.bmp", "Picture//A1//A1 0289.bmp", "Picture//A1//A1 0290.bmp",
"Picture//A1//A1 0291.bmp", "Picture//A1//A1 0292.bmp", "Picture//A1//A1 0293.bmp", "Picture//A1//A1 0294.bmp", "Picture//A1//A1 0295.bmp", "Picture//A1//A1 0296.bmp", "Picture//A1//A1 0297.bmp", "Picture//A1//A1 0298.bmp", "Picture//A1//A1 0299.bmp", "Picture//A1//A1 0300.bmp",
"Picture//A1//A1 0301.bmp", "Picture//A1//A1 0302.bmp", "Picture//A1//A1 0303.bmp", "Picture//A1//A1 0304.bmp", "Picture//A1//A1 0305.bmp", "Picture//A1//A1 0306.bmp", "Picture//A1//A1 0307.bmp", "Picture//A1//A1 0308.bmp", "Picture//A1//A1 0309.bmp", "Picture//A1//A1 0310.bmp",
"Picture//A1//A1 0311.bmp", "Picture//A1//A1 0312.bmp", "Picture//A1//A1 0313.bmp", "Picture//A1//A1 0314.bmp", "Picture//A1//A1 0315.bmp", "Picture//A1//A1 0316.bmp", "Picture//A1//A1 0317.bmp", "Picture//A1//A1 0318.bmp", "Picture//A1//A1 0319.bmp", "Picture//A1//A1 0320.bmp",
"Picture//A1//A1 0321.bmp", "Picture//A1//A1 0322.bmp", "Picture//A1//A1 0323.bmp", "Picture//A1//A1 0324.bmp", "Picture//A1//A1 0325.bmp", "Picture//A1//A1 0326.bmp", "Picture//A1//A1 0327.bmp", "Picture//A1//A1 0328.bmp", "Picture//A1//A1 0329.bmp", "Picture//A1//A1 0330.bmp",
"Picture//A1//A1 0331.bmp", "Picture//A1//A1 0332.bmp", "Picture//A1//A1 0333.bmp", "Picture//A1//A1 0334.bmp", "Picture//A1//A1 0335.bmp", "Picture//A1//A1 0336.bmp", "Picture//A1//A1 0337.bmp", "Picture//A1//A1 0338.bmp", "Picture//A1//A1 0339.bmp", "Picture//A1//A1 0340.bmp",
"Picture//A1//A1 0341.bmp", "Picture//A1//A1 0342.bmp", "Picture//A1//A1 0343.bmp", "Picture//A1//A1 0344.bmp", "Picture//A1//A1 0345.bmp", "Picture//A1//A1 0346.bmp", "Picture//A1//A1 0347.bmp", "Picture//A1//A1 0348.bmp", "Picture//A1//A1 0349.bmp", "Picture//A1//A1 0350.bmp",
"Picture//A1//A1 0351.bmp", "Picture//A1//A1 0352.bmp", "Picture//A1//A1 0353.bmp", "Picture//A1//A1 0354.bmp", "Picture//A1//A1 0355.bmp", "Picture//A1//A1 0356.bmp", "Picture//A1//A1 0357.bmp", "Picture//A1//A1 0358.bmp", "Picture//A1//A1 0359.bmp", "Picture//A1//A1 0360.bmp",
"Picture//A1//A1 0361.bmp", "Picture//A1//A1 0362.bmp", "Picture//A1//A1 0363.bmp", "Picture//A1//A1 0364.bmp", "Picture//A1//A1 0365.bmp", "Picture//A1//A1 0366.bmp", "Picture//A1//A1 0367.bmp", "Picture//A1//A1 0368.bmp", "Picture//A1//A1 0369.bmp", "Picture//A1//A1 0370.bmp",
"Picture//A1//A1 0371.bmp", "Picture//A1//A1 0372.bmp", "Picture//A1//A1 0373.bmp", "Picture//A1//A1 0374.bmp", "Picture//A1//A1 0375.bmp", "Picture//A1//A1 0376.bmp", "Picture//A1//A1 0377.bmp", "Picture//A1//A1 0378.bmp", "Picture//A1//A1 0379.bmp", "Picture//A1//A1 0380.bmp",
"Picture//A1//A1 0381.bmp", "Picture//A1//A1 0382.bmp", "Picture//A1//A1 0383.bmp", "Picture//A1//A1 0384.bmp", "Picture//A1//A1 0385.bmp", "Picture//A1//A1 0386.bmp", "Picture//A1//A1 0387.bmp", "Picture//A1//A1 0388.bmp", "Picture//A1//A1 0389.bmp", "Picture//A1//A1 0390.bmp",
"Picture//A1//A1 0391.bmp", "Picture//A1//A1 0392.bmp", "Picture//A1//A1 0393.bmp", "Picture//A1//A1 0394.bmp", "Picture//A1//A1 0395.bmp", "Picture//A1//A1 0396.bmp", "Picture//A1//A1 0397.bmp", "Picture//A1//A1 0398.bmp", "Picture//A1//A1 0399.bmp", "Picture//A1//A1 0400.bmp",
"Picture//A1//A1 0401.bmp", "Picture//A1//A1 0402.bmp", "Picture//A1//A1 0403.bmp", "Picture//A1//A1 0404.bmp", "Picture//A1//A1 0405.bmp", "Picture//A1//A1 0406.bmp", "Picture//A1//A1 0407.bmp", "Picture//A1//A1 0408.bmp", "Picture//A1//A1 0409.bmp", "Picture//A1//A1 0410.bmp",
"Picture//A1//A1 0411.bmp", "Picture//A1//A1 0412.bmp", "Picture//A1//A1 0413.bmp", "Picture//A1//A1 0414.bmp", "Picture//A1//A1 0415.bmp", "Picture//A1//A1 0416.bmp", "Picture//A1//A1 0417.bmp", "Picture//A1//A1 0418.bmp", "Picture//A1//A1 0419.bmp", "Picture//A1//A1 0420.bmp",
"Picture//A1//A1 0421.bmp", "Picture//A1//A1 0422.bmp", "Picture//A1//A1 0423.bmp", "Picture//A1//A1 0424.bmp", "Picture//A1//A1 0425.bmp", "Picture//A1//A1 0426.bmp", "Picture//A1//A1 0427.bmp", "Picture//A1//A1 0428.bmp", "Picture//A1//A1 0429.bmp", "Picture//A1//A1 0430.bmp",
"Picture//A1//A1 0431.bmp", "Picture//A1//A1 0432.bmp", "Picture//A1//A1 0433.bmp", "Picture//A1//A1 0434.bmp", "Picture//A1//A1 0435.bmp", "Picture//A1//A1 0436.bmp", "Picture//A1//A1 0437.bmp", "Picture//A1//A1 0438.bmp", "Picture//A1//A1 0439.bmp", "Picture//A1//A1 0440.bmp",
"Picture//A1//A1 0441.bmp", "Picture//A1//A1 0442.bmp", "Picture//A1//A1 0443.bmp", "Picture//A1//A1 0444.bmp", "Picture//A1//A1 0445.bmp", "Picture//A1//A1 0446.bmp", "Picture//A1//A1 0447.bmp", "Picture//A1//A1 0448.bmp", "Picture//A1//A1 0449.bmp", "Picture//A1//A1 0450.bmp",
"Picture//A1//A1 0451.bmp", "Picture//A1//A1 0452.bmp", "Picture//A1//A1 0453.bmp", "Picture//A1//A1 0454.bmp", "Picture//A1//A1 0455.bmp", "Picture//A1//A1 0456.bmp", "Picture//A1//A1 0457.bmp", "Picture//A1//A1 0458.bmp", "Picture//A1//A1 0459.bmp", "Picture//A1//A1 0460.bmp",
"Picture//A1//A1 0461.bmp", "Picture//A1//A1 0462.bmp", "Picture//A1//A1 0463.bmp", "Picture//A1//A1 0464.bmp", "Picture//A1//A1 0465.bmp", "Picture//A1//A1 0466.bmp", "Picture//A1//A1 0167.bmp", "Picture//A1//A1 0168.bmp", "Picture//A1//A1 0169.bmp", "Picture//A1//A1 0470.bmp",
"Picture//A1//A1 0471.bmp", "Picture//A1//A1 0472.bmp", "Picture//A1//A1 0473.bmp", "Picture//A1//A1 0474.bmp", "Picture//A1//A1 0475.bmp", "Picture//A1//A1 0476.bmp", "Picture//A1//A1 0477.bmp", "Picture//A1//A1 0478.bmp", "Picture//A1//A1 0479.bmp", "Picture//A1//A1 0480.bmp",
"Picture//A1//A1 0481.bmp", "Picture//A1//A1 0482.bmp", "Picture//A1//A1 0483.bmp", "Picture//A1//A1 0484.bmp", "Picture//A1//A1 0485.bmp", "Picture//A1//A1 0486.bmp", "Picture//A1//A1 0487.bmp", "Picture//A1//A1 0488.bmp", "Picture//A1//A1 0489.bmp", "Picture//A1//A1 0490.bmp",
"Picture//A1//A1 0491.bmp", "Picture//A1//A1 0492.bmp", "Picture//A1//A1 0493.bmp", "Picture//A1//A1 0494.bmp", "Picture//A1//A1 0495.bmp", "Picture//A1//A1 0496.bmp", "Picture//A1//A1 0497.bmp", "Picture//A1//A1 0498.bmp", "Picture//A1//A1 0499.bmp", "Picture//A1//A1 0500.bmp",
"Picture//A1//A1 0501.bmp", "Picture//A1//A1 0502.bmp", "Picture//A1//A1 0503.bmp", "Picture//A1//A1 0504.bmp", "Picture//A1//A1 0505.bmp", "Picture//A1//A1 0506.bmp", "Picture//A1//A1 0507.bmp", "Picture//A1//A1 0508.bmp", "Picture//A1//A1 0509.bmp", "Picture//A1//A1 0510.bmp",
"Picture//A1//A1 0511.bmp", "Picture//A1//A1 0512.bmp", "Picture//A1//A1 0513.bmp", "Picture//A1//A1 0514.bmp", "Picture//A1//A1 0515.bmp", "Picture//A1//A1 0516.bmp", "Picture//A1//A1 0517.bmp", "Picture//A1//A1 0518.bmp", "Picture//A1//A1 0519.bmp", "Picture//A1//A1 0520.bmp",
"Picture//A1//A1 0521.bmp", "Picture//A1//A1 0522.bmp", "Picture//A1//A1 0523.bmp", "Picture//A1//A1 0524.bmp", "Picture//A1//A1 0525.bmp", "Picture//A1//A1 0526.bmp", "Picture//A1//A1 0527.bmp", "Picture//A1//A1 0528.bmp", "Picture//A1//A1 0529.bmp", "Picture//A1//A1 0530.bmp",
"Picture//A1//A1 0531.bmp", "Picture//A1//A1 0532.bmp", "Picture//A1//A1 0533.bmp", "Picture//A1//A1 0534.bmp", "Picture//A1//A1 0535.bmp", "Picture//A1//A1 0536.bmp", "Picture//A1//A1 0537.bmp", "Picture//A1//A1 0538.bmp", "Picture//A1//A1 0539.bmp", "Picture//A1//A1 0540.bmp",
"Picture//A1//A1 0541.bmp", "Picture//A1//A1 0542.bmp", "Picture//A1//A1 0543.bmp", "Picture//A1//A1 0544.bmp", "Picture//A1//A1 0545.bmp", "Picture//A1//A1 0546.bmp", "Picture//A1//A1 0547.bmp", "Picture//A1//A1 0548.bmp", "Picture//A1//A1 0549.bmp", "Picture//A1//A1 0550.bmp",
"Picture//A1//A1 0551.bmp", "Picture//A1//A1 0552.bmp", "Picture//A1//A1 0553.bmp", "Picture//A1//A1 0554.bmp", "Picture//A1//A1 0555.bmp", "Picture//A1//A1 0556.bmp", "Picture//A1//A1 0557.bmp", "Picture//A1//A1 0558.bmp", "Picture//A1//A1 0559.bmp", "Picture//A1//A1 0560.bmp",
"Picture//A1//A1 0561.bmp", "Picture//A1//A1 0562.bmp", "Picture//A1//A1 0563.bmp", "Picture//A1//A1 0564.bmp", "Picture//A1//A1 0565.bmp", "Picture//A1//A1 0566.bmp", "Picture//A1//A1 0567.bmp", "Picture//A1//A1 0568.bmp", "Picture//A1//A1 0569.bmp", "Picture//A1//A1 0570.bmp",
"Picture//A1//A1 0571.bmp", "Picture//A1//A1 0572.bmp", "Picture//A1//A1 0573.bmp", "Picture//A1//A1 0574.bmp", "Picture//A1//A1 0575.bmp", "Picture//A1//A1 0576.bmp", "Picture//A1//A1 0577.bmp", "Picture//A1//A1 0578.bmp", "Picture//A1//A1 0579.bmp", "Picture//A1//A1 0580.bmp",
"Picture//A1//A1 0581.bmp", "Picture//A1//A1 0582.bmp", "Picture//A1//A1 0583.bmp", "Picture//A1//A1 0584.bmp", "Picture//A1//A1 0585.bmp", "Picture//A1//A1 0586.bmp", "Picture//A1//A1 0587.bmp", "Picture//A1//A1 0588.bmp", "Picture//A1//A1 0589.bmp", "Picture//A1//A1 0590.bmp",
"Picture//A1//A1 0591.bmp", "Picture//A1//A1 0592.bmp", "Picture//A1//A1 0593.bmp", "Picture//A1//A1 0594.bmp", "Picture//A1//A1 0595.bmp", "Picture//A1//A1 0596.bmp", "Picture//A1//A1 0597.bmp", "Picture//A1//A1 0598.bmp", "Picture//A1//A1 0599.bmp", "Picture//A1//A1 0600.bmp",
"Picture//A1//A1 0601.bmp", "Picture//A1//A1 0602.bmp", "Picture//A1//A1 0603.bmp", "Picture//A1//A1 0604.bmp", "Picture//A1//A1 0605.bmp", "Picture//A1//A1 0606.bmp", "Picture//A1//A1 0607.bmp", "Picture//A1//A1 0608.bmp", "Picture//A1//A1 0609.bmp", "Picture//A1//A1 0610.bmp",
"Picture//A1//A1 0611.bmp", "Picture//A1//A1 0612.bmp", "Picture//A1//A1 0613.bmp", "Picture//A1//A1 0614.bmp", "Picture//A1//A1 0615.bmp", "Picture//A1//A1 0616.bmp", "Picture//A1//A1 0617.bmp", "Picture//A1//A1 0618.bmp", "Picture//A1//A1 0619.bmp", "Picture//A1//A1 0620.bmp",
"Picture//A1//A1 0621.bmp", "Picture//A1//A1 0622.bmp", "Picture//A1//A1 0623.bmp", "Picture//A1//A1 0624.bmp", "Picture//A1//A1 0625.bmp", "Picture//A1//A1 0626.bmp", "Picture//A1//A1 0627.bmp", "Picture//A1//A1 0628.bmp", "Picture//A1//A1 0629.bmp", "Picture//A1//A1 0630.bmp",
"Picture//A1//A1 0631.bmp", "Picture//A1//A1 0632.bmp", "Picture//A1//A1 0633.bmp", "Picture//A1//A1 0634.bmp", "Picture//A1//A1 0635.bmp", "Picture//A1//A1 0636.bmp", "Picture//A1//A1 0637.bmp", "Picture//A1//A1 0638.bmp", "Picture//A1//A1 0639.bmp", "Picture//A1//A1 0640.bmp",
"Picture//A1//A1 0641.bmp", "Picture//A1//A1 0642.bmp", "Picture//A1//A1 0643.bmp", "Picture//A1//A1 0644.bmp", "Picture//A1//A1 0645.bmp", "Picture//A1//A1 0646.bmp", "Picture//A1//A1 0647.bmp", "Picture//A1//A1 0648.bmp", "Picture//A1//A1 0649.bmp", "Picture//A1//A1 0650.bmp",
"Picture//A1//A1 0651.bmp", "Picture//A1//A1 0652.bmp", "Picture//A1//A1 0653.bmp", "Picture//A1//A1 0654.bmp", "Picture//A1//A1 0655.bmp", "Picture//A1//A1 0656.bmp", "Picture//A1//A1 0657.bmp", "Picture//A1//A1 0658.bmp", "Picture//A1//A1 0659.bmp", "Picture//A1//A1 0660.bmp",
"Picture//A1//A1 0661.bmp", "Picture//A1//A1 0662.bmp", "Picture//A1//A1 0663.bmp", "Picture//A1//A1 0664.bmp", "Picture//A1//A1 0665.bmp", "Picture//A1//A1 0666.bmp", "Picture//A1//A1 0667.bmp", "Picture//A1//A1 0668.bmp", "Picture//A1//A1 0669.bmp", "Picture//A1//A1 0670.bmp",
"Picture//A1//A1 0671.bmp", "Picture//A1//A1 0672.bmp", "Picture//A1//A1 0673.bmp", "Picture//A1//A1 0674.bmp", "Picture//A1//A1 0675.bmp", "Picture//A1//A1 0676.bmp", "Picture//A1//A1 0677.bmp", "Picture//A1//A1 0678.bmp", "Picture//A1//A1 0679.bmp", "Picture//A1//A1 0680.bmp",
"Picture//A1//A1 0681.bmp", "Picture//A1//A1 0682.bmp", "Picture//A1//A1 0683.bmp", "Picture//A1//A1 0684.bmp", "Picture//A1//A1 0685.bmp", "Picture//A1//A1 0686.bmp", "Picture//A1//A1 0687.bmp", "Picture//A1//A1 0688.bmp", "Picture//A1//A1 0689.bmp", "Picture//A1//A1 0690.bmp",
"Picture//A1//A1 0691.bmp", "Picture//A1//A1 0692.bmp", "Picture//A1//A1 0693.bmp", "Picture//A1//A1 0694.bmp", "Picture//A1//A1 0695.bmp", "Picture//A1//A1 0696.bmp", "Picture//A1//A1 0697.bmp", "Picture//A1//A1 0698.bmp", "Picture//A1//A1 0699.bmp", "Picture//A1//A1 0700.bmp",
"Picture//A1//A1 0701.bmp", "Picture//A1//A1 0702.bmp", "Picture//A1//A1 0703.bmp", "Picture//A1//A1 0704.bmp", "Picture//A1//A1 0705.bmp", "Picture//A1//A1 0706.bmp", "Picture//A1//A1 0707.bmp", "Picture//A1//A1 0708.bmp", "Picture//A1//A1 0709.bmp", "Picture//A1//A1 0710.bmp",
"Picture//A1//A1 0711.bmp", "Picture//A1//A1 0712.bmp", "Picture//A1//A1 0713.bmp", "Picture//A1//A1 0714.bmp", "Picture//A1//A1 0715.bmp", "Picture//A1//A1 0716.bmp", "Picture//A1//A1 0717.bmp", "Picture//A1//A1 0718.bmp", "Picture//A1//A1 0719.bmp", "Picture//A1//A1 0720.bmp",
"Picture//A1//A1 0721.bmp", "Picture//A1//A1 0722.bmp", "Picture//A1//A1 0723.bmp", "Picture//A1//A1 0724.bmp", "Picture//A1//A1 0725.bmp", "Picture//A1//A1 0726.bmp", "Picture//A1//A1 0727.bmp", "Picture//A1//A1 0728.bmp", "Picture//A1//A1 0729.bmp", "Picture//A1//A1 0730.bmp",
"Picture//A1//A1 0731.bmp", "Picture//A1//A1 0732.bmp", "Picture//A1//A1 0733.bmp", "Picture//A1//A1 0734.bmp", "Picture//A1//A1 0735.bmp", "Picture//A1//A1 0736.bmp", "Picture//A1//A1 0737.bmp", "Picture//A1//A1 0738.bmp", "Picture//A1//A1 0739.bmp", "Picture//A1//A1 0740.bmp",
"Picture//A1//A1 0741.bmp", "Picture//A1//A1 0742.bmp", "Picture//A1//A1 0743.bmp", "Picture//A1//A1 0744.bmp", "Picture//A1//A1 0745.bmp", "Picture//A1//A1 0746.bmp", "Picture//A1//A1 0747.bmp", "Picture//A1//A1 0748.bmp", "Picture//A1//A1 0749.bmp", "Picture//A1//A1 0750.bmp",
"Picture//A1//A1 0751.bmp", "Picture//A1//A1 0752.bmp", "Picture//A1//A1 0753.bmp", "Picture//A1//A1 0754.bmp", "Picture//A1//A1 0755.bmp", "Picture//A1//A1 0756.bmp", "Picture//A1//A1 0757.bmp", "Picture//A1//A1 0758.bmp", "Picture//A1//A1 0759.bmp", "Picture//A1//A1 0760.bmp",
"Picture//A1//A1 0761.bmp", "Picture//A1//A1 0762.bmp", "Picture//A1//A1 0763.bmp", "Picture//A1//A1 0764.bmp", "Picture//A1//A1 0765.bmp", "Picture//A1//A1 0766.bmp", "Picture//A1//A1 0767.bmp", "Picture//A1//A1 0768.bmp", "Picture//A1//A1 0769.bmp", "Picture//A1//A1 0770.bmp",
"Picture//A1//A1 0771.bmp", "Picture//A1//A1 0772.bmp", "Picture//A1//A1 0773.bmp", "Picture//A1//A1 0774.bmp", "Picture//A1//A1 0775.bmp", "Picture//A1//A1 0776.bmp", "Picture//A1//A1 0777.bmp", "Picture//A1//A1 0778.bmp", "Picture//A1//A1 0779.bmp", "Picture//A1//A1 0780.bmp",
"Picture//A1//A1 0781.bmp", "Picture//A1//A1 0782.bmp", "Picture//A1//A1 0783.bmp", "Picture//A1//A1 0784.bmp", "Picture//A1//A1 0785.bmp", "Picture//A1//A1 0786.bmp", "Picture//A1//A1 0787.bmp", "Picture//A1//A1 0788.bmp", "Picture//A1//A1 0789.bmp", "Picture//A1//A1 0790.bmp",
"Picture//A1//A1 0791.bmp", "Picture//A1//A1 0792.bmp", "Picture//A1//A1 0793.bmp", "Picture//A1//A1 0794.bmp", "Picture//A1//A1 0795.bmp", "Picture//A1//A1 0796.bmp", "Picture//A1//A1 0797.bmp", "Picture//A1//A1 0798.bmp", "Picture//A1//A1 0799.bmp", "Picture//A1//A1 0800.bmp",
"Picture//A1//A1 0801.bmp", "Picture//A1//A1 0802.bmp", "Picture//A1//A1 0803.bmp", "Picture//A1//A1 0804.bmp", "Picture//A1//A1 0805.bmp", "Picture//A1//A1 0806.bmp", "Picture//A1//A1 0807.bmp", "Picture//A1//A1 0808.bmp", "Picture//A1//A1 0809.bmp", "Picture//A1//A1 0810.bmp",
"Picture//A1//A1 0811.bmp", "Picture//A1//A1 0812.bmp", "Picture//A1//A1 0813.bmp", "Picture//A1//A1 0814.bmp", "Picture//A1//A1 0815.bmp", "Picture//A1//A1 0816.bmp", "Picture//A1//A1 0817.bmp", "Picture//A1//A1 0818.bmp", "Picture//A1//A1 0819.bmp", "Picture//A1//A1 0820.bmp",
"Picture//A1//A1 0821.bmp", "Picture//A1//A1 0822.bmp", "Picture//A1//A1 0823.bmp", "Picture//A1//A1 0824.bmp", "Picture//A1//A1 0825.bmp", "Picture//A1//A1 0826.bmp", "Picture//A1//A1 0827.bmp", "Picture//A1//A1 0828.bmp", "Picture//A1//A1 0829.bmp", "Picture//A1//A1 0830.bmp",
"Picture//A1//A1 0831.bmp", "Picture//A1//A1 0832.bmp", "Picture//A1//A1 0833.bmp", "Picture//A1//A1 0834.bmp", "Picture//A1//A1 0835.bmp", "Picture//A1//A1 0836.bmp", "Picture//A1//A1 0837.bmp", "Picture//A1//A1 0838.bmp", "Picture//A1//A1 0839.bmp", "Picture//A1//A1 0840.bmp",
"Picture//A1//A1 0841.bmp", "Picture//A1//A1 0842.bmp", "Picture//A1//A1 0843.bmp", "Picture//A1//A1 0844.bmp", "Picture//A1//A1 0845.bmp", "Picture//A1//A1 0846.bmp", "Picture//A1//A1 0847.bmp", "Picture//A1//A1 0848.bmp", "Picture//A1//A1 0849.bmp", "Picture//A1//A1 0850.bmp",
"Picture//A1//A1 0851.bmp", "Picture//A1//A1 0852.bmp", "Picture//A1//A1 0853.bmp", "Picture//A1//A1 0854.bmp", "Picture//A1//A1 0855.bmp", "Picture//A1//A1 0856.bmp", "Picture//A1//A1 0857.bmp", "Picture//A1//A1 0858.bmp", "Picture//A1//A1 0859.bmp", "Picture//A1//A1 0860.bmp",
"Picture//A1//A1 0861.bmp", "Picture//A1//A1 0862.bmp", "Picture//A1//A1 0863.bmp", "Picture//A1//A1 0864.bmp", "Picture//A1//A1 0865.bmp", "Picture//A1//A1 0866.bmp", "Picture//A1//A1 0867.bmp", "Picture//A1//A1 0868.bmp", "Picture//A1//A1 0869.bmp", "Picture//A1//A1 0870.bmp",
"Picture//A1//A1 0871.bmp", "Picture//A1//A1 0872.bmp", "Picture//A1//A1 0873.bmp", "Picture//A1//A1 0874.bmp", "Picture//A1//A1 0875.bmp", "Picture//A1//A1 0876.bmp", "Picture//A1//A1 0877.bmp", "Picture//A1//A1 0878.bmp", "Picture//A1//A1 0879.bmp", "Picture//A1//A1 0880.bmp",
"Picture//A1//A1 0881.bmp", "Picture//A1//A1 0882.bmp", "Picture//A1//A1 0883.bmp", "Picture//A1//A1 0884.bmp", "Picture//A1//A1 0885.bmp", "Picture//A1//A1 0886.bmp", "Picture//A1//A1 0887.bmp", "Picture//A1//A1 0888.bmp", "Picture//A1//A1 0889.bmp", "Picture//A1//A1 0890.bmp",
"Picture//A1//A1 0891.bmp", "Picture//A1//A1 0892.bmp", "Picture//A1//A1 0893.bmp", "Picture//A1//A1 0894.bmp", "Picture//A1//A1 0895.bmp", "Picture//A1//A1 0896.bmp", "Picture//A1//A1 0897.bmp", "Picture//A1//A1 0898.bmp", "Picture//A1//A1 0899.bmp", "Picture//A1//A1 0900.bmp",
"Picture//A1//A1 0901.bmp", "Picture//A1//A1 0902.bmp", "Picture//A1//A1 0903.bmp", "Picture//A1//A1 0904.bmp", "Picture//A1//A1 0905.bmp", "Picture//A1//A1 0906.bmp", "Picture//A1//A1 0907.bmp", "Picture//A1//A1 0908.bmp", "Picture//A1//A1 0909.bmp", "Picture//A1//A1 0910.bmp",
"Picture//A1//A1 0911.bmp", "Picture//A1//A1 0912.bmp", "Picture//A1//A1 0913.bmp", "Picture//A1//A1 0914.bmp", "Picture//A1//A1 0915.bmp", "Picture//A1//A1 0916.bmp", "Picture//A1//A1 0917.bmp", "Picture//A1//A1 0918.bmp", "Picture//A1//A1 0919.bmp", "Picture//A1//A1 0920.bmp",
"Picture//A1//A1 0921.bmp", "Picture//A1//A1 0922.bmp", "Picture//A1//A1 0923.bmp", "Picture//A1//A1 0924.bmp", "Picture//A1//A1 0925.bmp", "Picture//A1//A1 0926.bmp", "Picture//A1//A1 0927.bmp", "Picture//A1//A1 0928.bmp", "Picture//A1//A1 0929.bmp", "Picture//A1//A1 0930.bmp",
"Picture//A1//A1 0931.bmp", "Picture//A1//A1 0932.bmp", "Picture//A1//A1 0933.bmp", "Picture//A1//A1 0934.bmp", "Picture//A1//A1 0935.bmp", "Picture//A1//A1 0936.bmp", "Picture//A1//A1 0937.bmp", "Picture//A1//A1 0938.bmp", "Picture//A1//A1 0939.bmp", "Picture//A1//A1 0940.bmp",
"Picture//A1//A1 0941.bmp", "Picture//A1//A1 0942.bmp", "Picture//A1//A1 0943.bmp", "Picture//A1//A1 0944.bmp", "Picture//A1//A1 0945.bmp", "Picture//A1//A1 0946.bmp", "Picture//A1//A1 0947.bmp", "Picture//A1//A1 0948.bmp", "Picture//A1//A1 0949.bmp", "Picture//A1//A1 0950.bmp",
"Picture//A1//A1 0951.bmp", "Picture//A1//A1 0952.bmp", "Picture//A1//A1 0953.bmp", "Picture//A1//A1 0954.bmp", "Picture//A1//A1 0955.bmp", "Picture//A1//A1 0956.bmp", "Picture//A1//A1 0957.bmp", "Picture//A1//A1 0958.bmp", "Picture//A1//A1 0959.bmp", "Picture//A1//A1 0960.bmp",
"Picture//A1//A1 0961.bmp", "Picture//A1//A1 0962.bmp", "Picture//A1//A1 0963.bmp", "Picture//A1//A1 0964.bmp", "Picture//A1//A1 0965.bmp", "Picture//A1//A1 0966.bmp", "Picture//A1//A1 0967.bmp", "Picture//A1//A1 0968.bmp", "Picture//A1//A1 0969.bmp", "Picture//A1//A1 0970.bmp",
"Picture//A1//A1 0971.bmp", "Picture//A1//A1 0972.bmp", "Picture//A1//A1 0973.bmp", "Picture//A1//A1 0974.bmp", "Picture//A1//A1 0975.bmp", "Picture//A1//A1 0976.bmp", "Picture//A1//A1 0977.bmp", "Picture//A1//A1 0978.bmp", "Picture//A1//A1 0979.bmp", "Picture//A1//A1 0980.bmp",
"Picture//A1//A1 0981.bmp", "Picture//A1//A1 0982.bmp", "Picture//A1//A1 0983.bmp", "Picture//A1//A1 0984.bmp", "Picture//A1//A1 0985.bmp", "Picture//A1//A1 0986.bmp", "Picture//A1//A1 0987.bmp", "Picture//A1//A1 0988.bmp", "Picture//A1//A1 0989.bmp", "Picture//A1//A1 0990.bmp",
"Picture//A1//A1 0991.bmp", "Picture//A1//A1 0992.bmp", "Picture//A1//A1 0993.bmp", "Picture//A1//A1 0994.bmp", "Picture//A1//A1 0995.bmp", "Picture//A1//A1 0996.bmp", "Picture//A1//A1 0997.bmp", "Picture//A1//A1 0998.bmp", "Picture//A1//A1 0999.bmp", "Picture//A1//A1 1000.bmp",
"Picture//A1//A1 1001.bmp", "Picture//A1//A1 1002.bmp", "Picture//A1//A1 1003.bmp", "Picture//A1//A1 1004.bmp", "Picture//A1//A1 1005.bmp", "Picture//A1//A1 1006.bmp", "Picture//A1//A1 1007.bmp", "Picture//A1//A1 1008.bmp", "Picture//A1//A1 1009.bmp", "Picture//A1//A1 1010.bmp",
"Picture//A1//A1 1011.bmp", "Picture//A1//A1 1012.bmp", "Picture//A1//A1 1013.bmp", "Picture//A1//A1 1014.bmp", "Picture//A1//A1 1015.bmp", "Picture//A1//A1 1016.bmp", "Picture//A1//A1 1017.bmp", "Picture//A1//A1 1018.bmp", "Picture//A1//A1 1019.bmp", "Picture//A1//A1 1020.bmp",
"Picture//A1//A1 1021.bmp", "Picture//A1//A1 1022.bmp", "Picture//A1//A1 1023.bmp", "Picture//A1//A1 1024.bmp", "Picture//A1//A1 1025.bmp", "Picture//A1//A1 1026.bmp", "Picture//A1//A1 0027.bmp", "Picture//A1//A1 0028.bmp", "Picture//A1//A1 1029.bmp", "Picture//A1//A1 1030.bmp",
"Picture//A1//A1 1031.bmp", "Picture//A1//A1 1032.bmp", "Picture//A1//A1 1033.bmp", "Picture//A1//A1 1034.bmp", "Picture//A1//A1 1035.bmp", "Picture//A1//A1 1036.bmp", "Picture//A1//A1 1037.bmp", "Picture//A1//A1 1038.bmp", "Picture//A1//A1 1039.bmp", "Picture//A1//A1 1040.bmp",
"Picture//A1//A1 1041.bmp", "Picture//A1//A1 1042.bmp", "Picture//A1//A1 1043.bmp", "Picture//A1//A1 1044.bmp", "Picture//A1//A1 1045.bmp", "Picture//A1//A1 1046.bmp", "Picture//A1//A1 1047.bmp", "Picture//A1//A1 1048.bmp", "Picture//A1//A1 1049.bmp", "Picture//A1//A1 1050.bmp",
"Picture//A1//A1 1051.bmp", "Picture//A1//A1 1052.bmp", "Picture//A1//A1 1053.bmp", "Picture//A1//A1 1054.bmp", "Picture//A1//A1 1055.bmp", "Picture//A1//A1 1056.bmp", "Picture//A1//A1 1057.bmp", "Picture//A1//A1 1058.bmp", "Picture//A1//A1 1059.bmp", "Picture//A1//A1 1060.bmp",
"Picture//A1//A1 1061.bmp", "Picture//A1//A1 1062.bmp", "Picture//A1//A1 1063.bmp", "Picture//A1//A1 1064.bmp", "Picture//A1//A1 1065.bmp", "Picture//A1//A1 1066.bmp", "Picture//A1//A1 1067.bmp", "Picture//A1//A1 1068.bmp", "Picture//A1//A1 1069.bmp", "Picture//A1//A1 1070.bmp",
"Picture//A1//A1 1071.bmp", "Picture//A1//A1 1072.bmp", "Picture//A1//A1 1073.bmp", "Picture//A1//A1 1074.bmp", "Picture//A1//A1 1075.bmp", "Picture//A1//A1 1076.bmp", "Picture//A1//A1 1077.bmp", "Picture//A1//A1 1078.bmp", "Picture//A1//A1 1079.bmp", "Picture//A1//A1 1080.bmp",
"Picture//A1//A1 1081.bmp", "Picture//A1//A1 1082.bmp", "Picture//A1//A1 1083.bmp", "Picture//A1//A1 1084.bmp", "Picture//A1//A1 1085.bmp", "Picture//A1//A1 1086.bmp", "Picture//A1//A1 1087.bmp", "Picture//A1//A1 1088.bmp", "Picture//A1//A1 1089.bmp", "Picture//A1//A1 1090.bmp",
"Picture//A1//A1 1091.bmp", "Picture//A1//A1 1092.bmp", "Picture//A1//A1 1093.bmp", "Picture//A1//A1 1094.bmp", "Picture//A1//A1 1095.bmp", "Picture//A1//A1 1096.bmp", "Picture//A1//A1 1097.bmp", "Picture//A1//A1 1098.bmp", "Picture//A1//A1 1099.bmp", "Picture//A1//A1 1100.bmp",
"Picture//A1//A1 1101.bmp", "Picture//A1//A1 1102.bmp", "Picture//A1//A1 1103.bmp", "Picture//A1//A1 1104.bmp", "Picture//A1//A1 1105.bmp", "Picture//A1//A1 1106.bmp", "Picture//A1//A1 1107.bmp", "Picture//A1//A1 1108.bmp", "Picture//A1//A1 1109.bmp", "Picture//A1//A1 1110.bmp",
"Picture//A1//A1 1111.bmp", "Picture//A1//A1 1112.bmp", "Picture//A1//A1 1113.bmp", "Picture//A1//A1 1114.bmp", "Picture//A1//A1 1115.bmp", "Picture//A1//A1 1116.bmp", "Picture//A1//A1 1117.bmp", "Picture//A1//A1 1118.bmp", "Picture//A1//A1 1119.bmp", "Picture//A1//A1 1120.bmp",
"Picture//A1//A1 1121.bmp", "Picture//A1//A1 1122.bmp", "Picture//A1//A1 1123.bmp", "Picture//A1//A1 1124.bmp", "Picture//A1//A1 1125.bmp", "Picture//A1//A1 1126.bmp", "Picture//A1//A1 1127.bmp", "Picture//A1//A1 1128.bmp", "Picture//A1//A1 1129.bmp", "Picture//A1//A1 1130.bmp",
"Picture//A1//A1 1131.bmp", "Picture//A1//A1 1132.bmp", "Picture//A1//A1 1133.bmp", "Picture//A1//A1 1134.bmp", "Picture//A1//A1 1135.bmp", "Picture//A1//A1 1136.bmp", "Picture//A1//A1 1137.bmp", "Picture//A1//A1 1138.bmp", "Picture//A1//A1 1139.bmp", "Picture//A1//A1 1140.bmp",
"Picture//A1//A1 1141.bmp", "Picture//A1//A1 1142.bmp", "Picture//A1//A1 1143.bmp", "Picture//A1//A1 1144.bmp", "Picture//A1//A1 1145.bmp", "Picture//A1//A1 1146.bmp", "Picture//A1//A1 1147.bmp", "Picture//A1//A1 1148.bmp", "Picture//A1//A1 1149.bmp", "Picture//A1//A1 1150.bmp",
"Picture//A1//A1 1151.bmp", "Picture//A1//A1 1152.bmp", "Picture//A1//A1 1153.bmp", "Picture//A1//A1 1154.bmp", "Picture//A1//A1 1155.bmp", "Picture//A1//A1 1156.bmp", "Picture//A1//A1 1157.bmp", "Picture//A1//A1 1158.bmp", "Picture//A1//A1 1159.bmp", "Picture//A1//A1 1160.bmp",
"Picture//A1//A1 1161.bmp", "Picture//A1//A1 1162.bmp", "Picture//A1//A1 1163.bmp", "Picture//A1//A1 1164.bmp", "Picture//A1//A1 1165.bmp", "Picture//A1//A1 1166.bmp", "Picture//A1//A1 1167.bmp", "Picture//A1//A1 1168.bmp", "Picture//A1//A1 1169.bmp", "Picture//A1//A1 1170.bmp",
"Picture//A1//A1 1171.bmp", "Picture//A1//A1 1172.bmp", "Picture//A1//A1 1173.bmp", "Picture//A1//A1 1174.bmp", "Picture//A1//A1 1175.bmp", "Picture//A1//A1 1176.bmp", "Picture//A1//A1 1177.bmp", "Picture//A1//A1 1178.bmp", "Picture//A1//A1 1179.bmp", "Picture//A1//A1 1180.bmp",
"Picture//A1//A1 1181.bmp", "Picture//A1//A1 1182.bmp", "Picture//A1//A1 1183.bmp", "Picture//A1//A1 1184.bmp", "Picture//A1//A1 1185.bmp", "Picture//A1//A1 1186.bmp", "Picture//A1//A1 1187.bmp", "Picture//A1//A1 1188.bmp", "Picture//A1//A1 1189.bmp", "Picture//A1//A1 1190.bmp",
"Picture//A1//A1 1191.bmp", "Picture//A1//A1 1192.bmp", "Picture//A1//A1 1193.bmp", "Picture//A1//A1 1194.bmp", "Picture//A1//A1 1195.bmp", "Picture//A1//A1 1196.bmp", "Picture//A1//A1 1197.bmp", "Picture//A1//A1 1198.bmp", "Picture//A1//A1 1199.bmp", "Picture//A1//A1 1200.bmp",
"Picture//A1//A1 1201.bmp", "Picture//A1//A1 1202.bmp", "Picture//A1//A1 1203.bmp", "Picture//A1//A1 1204.bmp", "Picture//A1//A1 1205.bmp", "Picture//A1//A1 1206.bmp", "Picture//A1//A1 1207.bmp", "Picture//A1//A1 1208.bmp", "Picture//A1//A1 1209.bmp", "Picture//A1//A1 1210.bmp",
"Picture//A1//A1 1211.bmp", "Picture//A1//A1 1212.bmp", "Picture//A1//A1 1213.bmp", "Picture//A1//A1 1214.bmp", "Picture//A1//A1 1215.bmp", "Picture//A1//A1 1216.bmp", "Picture//A1//A1 1217.bmp", "Picture//A1//A1 1218.bmp", "Picture//A1//A1 1219.bmp", "Picture//A1//A1 1220.bmp",
"Picture//A1//A1 1221.bmp", "Picture//A1//A1 1222.bmp", "Picture//A1//A1 1223.bmp", "Picture//A1//A1 1224.bmp", "Picture//A1//A1 1225.bmp", "Picture//A1//A1 1226.bmp", "Picture//A1//A1 1227.bmp", "Picture//A1//A1 1228.bmp", "Picture//A1//A1 1229.bmp", "Picture//A1//A1 1230.bmp",
"Picture//A1//A1 1231.bmp", "Picture//A1//A1 1232.bmp", "Picture//A1//A1 1233.bmp", "Picture//A1//A1 1234.bmp", "Picture//A1//A1 1235.bmp", "Picture//A1//A1 1236.bmp", "Picture//A1//A1 1237.bmp", "Picture//A1//A1 1238.bmp", "Picture//A1//A1 1239.bmp", "Picture//A1//A1 1240.bmp",
"Picture//A1//A1 1241.bmp", "Picture//A1//A1 1242.bmp", "Picture//A1//A1 1243.bmp", "Picture//A1//A1 1244.bmp", "Picture//A1//A1 1245.bmp", "Picture//A1//A1 1246.bmp", "Picture//A1//A1 1247.bmp", "Picture//A1//A1 1248.bmp", "Picture//A1//A1 1249.bmp", "Picture//A1//A1 1250.bmp",
"Picture//A1//A1 1251.bmp", "Picture//A1//A1 1252.bmp", "Picture//A1//A1 1253.bmp", "Picture//A1//A1 1254.bmp", "Picture//A1//A1 1255.bmp", "Picture//A1//A1 1256.bmp", "Picture//A1//A1 1257.bmp", "Picture//A1//A1 1258.bmp", "Picture//A1//A1 1259.bmp", "Picture//A1//A1 1260.bmp",
"Picture//A1//A1 1261.bmp", "Picture//A1//A1 1262.bmp", "Picture//A1//A1 1263.bmp", "Picture//A1//A1 1264.bmp", "Picture//A1//A1 1265.bmp", "Picture//A1//A1 1266.bmp", "Picture//A1//A1 1267.bmp", "Picture//A1//A1 1268.bmp", "Picture//A1//A1 1269.bmp", "Picture//A1//A1 1270.bmp",
"Picture//A1//A1 1271.bmp", "Picture//A1//A1 1272.bmp", "Picture//A1//A1 1273.bmp", "Picture//A1//A1 1274.bmp", "Picture//A1//A1 1275.bmp", "Picture//A1//A1 1276.bmp", "Picture//A1//A1 1277.bmp", "Picture//A1//A1 1278.bmp", "Picture//A1//A1 1279.bmp", "Picture//A1//A1 1280.bmp",
"Picture//A1//A1 1281.bmp", "Picture//A1//A1 1282.bmp", "Picture//A1//A1 1283.bmp", "Picture//A1//A1 1284.bmp", "Picture//A1//A1 1285.bmp", "Picture//A1//A1 1286.bmp", "Picture//A1//A1 1287.bmp" };

char edestroy[500][50] = {"Picture//EE//ee 001.bmp","Picture//EE//ee 002.bmp","Picture//EE//ee 003.bmp","Picture//EE//ee 004.bmp","Picture//EE//ee 005.bmp","Picture//EE//ee 006.bmp","Picture//EE//ee 007.bmp","Picture//EE//ee 008.bmp","Picture//EE//ee 009.bmp","Picture//EE//ee 010.bmp","Picture//EE//ee 011.bmp","Picture//EE//ee 012.bmp","Picture//EE//ee 013.bmp","Picture//EE//ee 014.bmp","Picture//EE//ee 015.bmp","Picture//EE//ee 016.bmp","Picture//EE//ee 017.bmp","Picture//EE//ee 018.bmp",
"Picture//EE//ee 019.bmp","Picture//EE//ee 020.bmp","Picture//EE//ee 021.bmp","Picture//EE//ee 022.bmp","Picture//EE//ee 023.bmp","Picture//EE//ee 024.bmp","Picture//EE//ee 025.bmp","Picture//EE//ee 026.bmp","Picture//EE//ee 027.bmp","Picture//EE//ee 028.bmp","Picture//EE//ee 029.bmp","Picture//EE//ee 030.bmp","Picture//EE//ee 031.bmp","Picture//EE//ee 032.bmp","Picture//EE//ee 033.bmp","Picture//EE//ee 034.bmp","Picture//EE//ee 035.bmp","Picture//EE//ee 036.bmp",
"Picture//EE//ee 037.bmp","Picture//EE//ee 038.bmp","Picture//EE//ee 039.bmp","Picture//EE//ee 040.bmp","Picture//EE//ee 041.bmp","Picture//EE//ee 042.bmp","Picture//EE//ee 043.bmp","Picture//EE//ee 044.bmp","Picture//EE//ee 045.bmp","Picture//EE//ee 046.bmp","Picture//EE//ee 047.bmp","Picture//EE//ee 048.bmp","Picture//EE//ee 049.bmp","Picture//EE//ee 050.bmp","Picture//EE//ee 051.bmp","Picture//EE//ee 052.bmp","Picture//EE//ee 053.bmp","Picture//EE//ee 054.bmp",
"Picture//EE//ee 055.bmp","Picture//EE//ee 056.bmp","Picture//EE//ee 057.bmp","Picture//EE//ee 058.bmp","Picture//EE//ee 059.bmp","Picture//EE//ee 060.bmp","Picture//EE//ee 061.bmp","Picture//EE//ee 062.bmp","Picture//EE//ee 063.bmp","Picture//EE//ee 064.bmp","Picture//EE//ee 065.bmp","Picture//EE//ee 066.bmp","Picture//EE//ee 067.bmp","Picture//EE//ee 068.bmp","Picture//EE//ee 069.bmp","Picture//EE//ee 070.bmp","Picture//EE//ee 071.bmp","Picture//EE//ee 072.bmp",
"Picture//EE//ee 073.bmp","Picture//EE//ee 074.bmp","Picture//EE//ee 075.bmp","Picture//EE//ee 076.bmp","Picture//EE//ee 077.bmp","Picture//EE//ee 078.bmp","Picture//EE//ee 079.bmp","Picture//EE//ee 080.bmp","Picture//EE//ee 081.bmp","Picture//EE//ee 082.bmp","Picture//EE//ee 083.bmp","Picture//EE//ee 084.bmp","Picture//EE//ee 085.bmp","Picture//EE//ee 086.bmp","Picture//EE//ee 087.bmp","Picture//EE//ee 088.bmp","Picture//EE//ee 089.bmp","Picture//EE//ee 090.bmp",
"Picture//EE//ee 091.bmp","Picture//EE//ee 092.bmp","Picture//EE//ee 093.bmp","Picture//EE//ee 094.bmp","Picture//EE//ee 095.bmp","Picture//EE//ee 096.bmp","Picture//EE//ee 097.bmp","Picture//EE//ee 098.bmp","Picture//EE//ee 099.bmp","Picture//EE//ee 100.bmp","Picture//EE//ee 101.bmp","Picture//EE//ee 102.bmp","Picture//EE//ee 103.bmp","Picture//EE//ee 104.bmp","Picture//EE//ee 105.bmp","Picture//EE//ee 106.bmp","Picture//EE//ee 107.bmp","Picture//EE//ee 108.bmp",
"Picture//EE//ee 109.bmp","Picture//EE//ee 110.bmp","Picture//EE//ee 111.bmp","Picture//EE//ee 112.bmp","Picture//EE//ee 113.bmp","Picture//EE//ee 114.bmp","Picture//EE//ee 115.bmp","Picture//EE//ee 116.bmp","Picture//EE//ee 117.bmp","Picture//EE//ee 118.bmp","Picture//EE//ee 119.bmp","Picture//EE//ee 120.bmp","Picture//EE//ee 121.bmp","Picture//EE//ee 122.bmp","Picture//EE//ee 123.bmp","Picture//EE//ee 124.bmp","Picture//EE//ee 125.bmp","Picture//EE//ee 126.bmp",
"Picture//EE//ee 127.bmp","Picture//EE//ee 128.bmp","Picture//EE//ee 129.bmp","Picture//EE//ee 130.bmp","Picture//EE//ee 131.bmp","Picture//EE//ee 132.bmp","Picture//EE//ee 133.bmp","Picture//EE//ee 134.bmp","Picture//EE//ee 135.bmp","Picture//EE//ee 136.bmp","Picture//EE//ee 137.bmp","Picture//EE//ee 138.bmp","Picture//EE//ee 139.bmp","Picture//EE//ee 140.bmp","Picture//EE//ee 141.bmp","Picture//EE//ee 142.bmp","Picture//EE//ee 143.bmp","Picture//EE//ee 144.bmp",
"Picture//EE//ee 145.bmp","Picture//EE//ee 146.bmp","Picture//EE//ee 147.bmp","Picture//EE//ee 148.bmp","Picture//EE//ee 149.bmp","Picture//EE//ee 150.bmp","Picture//EE//ee 151.bmp","Picture//EE//ee 152.bmp","Picture//EE//ee 153.bmp","Picture//EE//ee 154.bmp","Picture//EE//ee 155.bmp","Picture//EE//ee 156.bmp","Picture//EE//ee 157.bmp","Picture//EE//ee 158.bmp","Picture//EE//ee 159.bmp","Picture//EE//ee 160.bmp","Picture//EE//ee 161.bmp","Picture//EE//ee 162.bmp",
"Picture//EE//ee 163.bmp","Picture//EE//ee 164.bmp","Picture//EE//ee 165.bmp","Picture//EE//ee 166.bmp","Picture//EE//ee 167.bmp","Picture//EE//ee 168.bmp","Picture//EE//ee 169.bmp","Picture//EE//ee 170.bmp","Picture//EE//ee 171.bmp","Picture//EE//ee 172.bmp","Picture//EE//ee 173.bmp","Picture//EE//ee 174.bmp","Picture//EE//ee 175.bmp","Picture//EE//ee 176.bmp","Picture//EE//ee 177.bmp","Picture//EE//ee 178.bmp","Picture//EE//ee 179.bmp","Picture//EE//ee 180.bmp",
"Picture//EE//ee 181.bmp","Picture//EE//ee 182.bmp","Picture//EE//ee 183.bmp","Picture//EE//ee 184.bmp","Picture//EE//ee 185.bmp","Picture//EE//ee 186.bmp","Picture//EE//ee 187.bmp","Picture//EE//ee 188.bmp","Picture//EE//ee 189.bmp","Picture//EE//ee 190.bmp","Picture//EE//ee 191.bmp","Picture//EE//ee 192.bmp","Picture//EE//ee 193.bmp","Picture//EE//ee 194.bmp","Picture//EE//ee 195.bmp","Picture//EE//ee 196.bmp","Picture//EE//ee 197.bmp","Picture//EE//ee 198.bmp",
"Picture//EE//ee 199.bmp","Picture//EE//ee 200.bmp","Picture//EE//ee 200.bmp","Picture//EE//ee 201.bmp","Picture//EE//ee 202.bmp","Picture//EE//ee 203.bmp","Picture//EE//ee 204.bmp","Picture//EE//ee 205.bmp","Picture//EE//ee 206.bmp","Picture//EE//ee 207.bmp","Picture//EE//ee 208.bmp","Picture//EE//ee 209.bmp","Picture//EE//ee 210.bmp","Picture//EE//ee 211.bmp","Picture//EE//ee 212.bmp","Picture//EE//ee 213.bmp","Picture//EE//ee 214.bmp","Picture//EE//ee 215.bmp",
"Picture//EE//ee 216.bmp","Picture//EE//ee 217.bmp","Picture//EE//ee 218.bmp","Picture//EE//ee 219.bmp","Picture//EE//ee 220.bmp","Picture//EE//ee 221.bmp","Picture//EE//ee 222.bmp","Picture//EE//ee 223.bmp","Picture//EE//ee 224.bmp","Picture//EE//ee 225.bmp","Picture//EE//ee 226.bmp","Picture//EE//ee 227.bmp","Picture//EE//ee 228.bmp","Picture//EE//ee 229.bmp","Picture//EE//ee 230.bmp","Picture//EE//ee 231.bmp","Picture//EE//ee 232.bmp","Picture//EE//ee 233.bmp",
"Picture//EE//ee 234.bmp","Picture//EE//ee 235.bmp","Picture//EE//ee 236.bmp","Picture//EE//ee 237.bmp","Picture//EE//ee 238.bmp","Picture//EE//ee 239.bmp","Picture//EE//ee 240.bmp","Picture//EE//ee 241.bmp","Picture//EE//ee 242.bmp","Picture//EE//ee 243.bmp","Picture//EE//ee 244.bmp","Picture//EE//ee 245.bmp","Picture//EE//ee 246.bmp","Picture//EE//ee 247.bmp","Picture//EE//ee 248.bmp","Picture//EE//ee 249.bmp","Picture//EE//ee 250.bmp","Picture//EE//ee 251.bmp",
"Picture//EE//ee 252.bmp","Picture//EE//ee 253.bmp","Picture//EE//ee 254.bmp","Picture//EE//ee 255.bmp","Picture//EE//ee 256.bmp","Picture//EE//ee 257.bmp","Picture//EE//ee 258.bmp","Picture//EE//ee 259.bmp","Picture//EE//ee 260.bmp","Picture//EE//ee 261.bmp","Picture//EE//ee 262.bmp","Picture//EE//ee 263.bmp","Picture//EE//ee 264.bmp","Picture//EE//ee 265.bmp","Picture//EE//ee 266.bmp","Picture//EE//ee 267.bmp","Picture//EE//ee 267.bmp","Picture//EE//ee 268.bmp",
"Picture//EE//ee 269.bmp","Picture//EE//ee 270.bmp","Picture//EE//ee 271.bmp","Picture//EE//ee 272.bmp","Picture//EE//ee 273.bmp","Picture//EE//ee 274.bmp","Picture//EE//ee 275.bmp","Picture//EE//ee 276.bmp","Picture//EE//ee 277.bmp","Picture//EE//ee 278.bmp","Picture//EE//ee 279.bmp","Picture//EE//ee 280.bmp","Picture//EE//ee 281.bmp","Picture//EE//ee 282.bmp","Picture//EE//ee 283.bmp","Picture//EE//ee 284.bmp","Picture//EE//ee 285.bmp","Picture//EE//ee 286.bmp",
"Picture//EE//ee 287.bmp","Picture//EE//ee 288.bmp","Picture//EE//ee 289.bmp","Picture//EE//ee 290.bmp","Picture//EE//ee 291.bmp","Picture//EE//ee 292.bmp","Picture//EE//ee 293.bmp","Picture//EE//ee 294.bmp","Picture//EE//ee 295.bmp","Picture//EE//ee 296.bmp","Picture//EE//ee 297.bmp","Picture//EE//ee 298.bmp","Picture//EE//ee 299.bmp","Picture//EE//ee 300.bmp","Picture//EE//ee 301.bmp","Picture//EE//ee 302.bmp","Picture//EE//ee 303.bmp","Picture//EE//ee 304.bmp",
"Picture//EE//ee 305.bmp","Picture//EE//ee 306.bmp","Picture//EE//ee 307.bmp","Picture//EE//ee 308.bmp","Picture//EE//ee 309.bmp","Picture//EE//ee 310.bmp","Picture//EE//ee 311.bmp","Picture//EE//ee 312.bmp","Picture//EE//ee 313.bmp","Picture//EE//ee 314.bmp","Picture//EE//ee 315.bmp","Picture//EE//ee 316.bmp","Picture//EE//ee 317.bmp","Picture//EE//ee 318.bmp","Picture//EE//ee 319.bmp","Picture//EE//ee 320.bmp","Picture//EE//ee 321.bmp","Picture//EE//ee 322.bmp",
"Picture//EE//ee 323.bmp","Picture//EE//ee 324.bmp","Picture//EE//ee 325.bmp","Picture//EE//ee 326.bmp","Picture//EE//ee 327.bmp","Picture//EE//ee 328.bmp","Picture//EE//ee 329.bmp","Picture//EE//ee 330.bmp","Picture//EE//ee 331.bmp","Picture//EE//ee 332.bmp","Picture//EE//ee 333.bmp","Picture//EE//ee 334.bmp","Picture//EE//ee 335.bmp","Picture//EE//ee 336.bmp","Picture//EE//ee 337.bmp","Picture//EE//ee 338.bmp","Picture//EE//ee 339.bmp","Picture//EE//ee 340.bmp",
"Picture//EE//ee 341.bmp","Picture//EE//ee 342.bmp","Picture//EE//ee 343.bmp","Picture//EE//ee 344.bmp","Picture//EE//ee 345.bmp","Picture//EE//ee 346.bmp","Picture//EE//ee 347.bmp","Picture//EE//ee 348.bmp","Picture//EE//ee 349.bmp","Picture//EE//ee 350.bmp","Picture//EE//ee 351.bmp","Picture//EE//ee 352.bmp","Picture//EE//ee 353.bmp","Picture//EE//ee 354.bmp","Picture//EE//ee 355.bmp","Picture//EE//ee 356.bmp","Picture//EE//ee 357.bmp","Picture//EE//ee 358.bmp",
"Picture//EE//ee 359.bmp","Picture//EE//ee 360.bmp","Picture//EE//ee 361.bmp","Picture//EE//ee 362.bmp","Picture//EE//ee 363.bmp","Picture//EE//ee 364.bmp","Picture//EE//ee 365.bmp","Picture//EE//ee 366.bmp","Picture//EE//ee 367.bmp","Picture//EE//ee 368.bmp","Picture//EE//ee 369.bmp","Picture//EE//ee 370.bmp","Picture//EE//ee 371.bmp","Picture//EE//ee 372.bmp","Picture//EE//ee 373.bmp","Picture//EE//ee 374.bmp","Picture//EE//ee 375.bmp","Picture//EE//ee 376.bmp",
"Picture//EE//ee 377.bmp","Picture//EE//ee 378.bmp","Picture//EE//ee 379.bmp","Picture//EE//ee 380.bmp","Picture//EE//ee 381.bmp","Picture//EE//ee 382.bmp","Picture//EE//ee 383.bmp","Picture//EE//ee 384.bmp","Picture//EE//ee 385.bmp","Picture//EE//ee 386.bmp","Picture//EE//ee 387.bmp","Picture//EE//ee 388.bmp","Picture//EE//ee 389.bmp","Picture//EE//ee 390.bmp","Picture//EE//ee 391.bmp","Picture//EE//ee 392.bmp","Picture//EE//ee 393.bmp","Picture//EE//ee 394.bmp",
"Picture//EE//ee 395.bmp","Picture//EE//ee 396.bmp","Picture//EE//ee 397.bmp","Picture//EE//ee 398.bmp","Picture//EE//ee 399.bmp","Picture//EE//ee 400.bmp","Picture//EE//ee 401.bmp","Picture//EE//ee 402.bmp","Picture//EE//ee 403.bmp","Picture//EE//ee 404.bmp","Picture//EE//ee 405.bmp","Picture//EE//ee 406.bmp","Picture//EE//ee 407.bmp","Picture//EE//ee 408.bmp","Picture//EE//ee 409.bmp","Picture//EE//ee 410.bmp","Picture//EE//ee 411.bmp","Picture//EE//ee 412.bmp",
"Picture//EE//ee 413.bmp","Picture//EE//ee 414.bmp","Picture//EE//ee 415.bmp","Picture//EE//ee 416.bmp","Picture//EE//ee 417.bmp","Picture//EE//ee 418.bmp","Picture//EE//ee 419.bmp","Picture//EE//ee 420.bmp","Picture//EE//ee 421.bmp","Picture//EE//ee 422.bmp","Picture//EE//ee 423.bmp","Picture//EE//ee 424.bmp","Picture//EE//ee 425.bmp","Picture//EE//ee 426.bmp","Picture//EE//ee 427.bmp","Picture//EE//ee 428.bmp","Picture//EE//ee 429.bmp","Picture//EE//ee 430.bmp",
"Picture//EE//ee 431.bmp","Picture//EE//ee 432.bmp","Picture//EE//ee 433.bmp","Picture//EE//ee 434.bmp","Picture//EE//ee 435.bmp","Picture//EE//ee 418.bmp","Picture//EE//ee 419.bmp","Picture//EE//ee 420.bmp","Picture//EE//ee 421.bmp","Picture//EE//ee 422.bmp","Picture//EE//ee 423.bmp","Picture//EE//ee 424.bmp","Picture//EE//ee 425.bmp","Picture//EE//ee 426.bmp","Picture//EE//ee 427.bmp","Picture//EE//ee 428.bmp","Picture//EE//ee 429.bmp","Picture//EE//ee 430.bmp",
"Picture//EE//ee 431.bmp","Picture//EE//ee 432.bmp","Picture//EE//ee 433.bmp","Picture//EE//ee 434.bmp","Picture//EE//ee 435.bmp","Picture//EE//ee 436.bmp","Picture//EE//ee 437.bmp","Picture//EE//ee 438.bmp","Picture//EE//ee 439.bmp","Picture//EE//ee 440.bmp","Picture//EE//ee 441.bmp","Picture//EE//ee 442.bmp","Picture//EE//ee 443.bmp","Picture//EE//ee 444.bmp","Picture//EE//ee 445.bmp","Picture//EE//ee 446.bmp","Picture//EE//ee 447.bmp","Picture//EE//ee 448.bmp",
"Picture//EE//ee 449.bmp","Picture//EE//ee 450.bmp","Picture//EE//ee 451.bmp","Picture//EE//ee 452.bmp","Picture//EE//ee 453.bmp","Picture//EE//ee 454.bmp","Picture//EE//ee 455.bmp","Picture//EE//ee 456.bmp","Picture//EE//ee 457.bmp","Picture//EE//ee 458.bmp","Picture//EE//ee 459.bmp","Picture//EE//ee 460.bmp","Picture//EE//ee 461.bmp","Picture//EE//ee 462.bmp","Picture//EE//ee 463.bmp","Picture//EE//ee 464.bmp","Picture//EE//ee 465.bmp","Picture//EE//ee 466.bmp",
"Picture//EE//ee 467.bmp","Picture//EE//ee 468.bmp","Picture//EE//ee 469.bmp","Picture//EE//ee 470.bmp","Picture//EE//ee 471.bmp","Picture//EE//ee 472.bmp","Picture//EE//ee 473.bmp","Picture//EE//ee 474.bmp","Picture//EE//ee 475.bmp","Picture//EE//ee 476.bmp","Picture//EE//ee 477.bmp","Picture//EE//ee 478.bmp","Picture//EE//ee 479.bmp"};


char pdestroy[282][50] = {"Picture//PE//PE 001.bmp","Picture//PE//PE 002.bmp", "Picture//PE//PE 003.bmp", "Picture//PE//PE 004.bmp", "Picture//PE//PE 005.bmp", "Picture//PE//PE 006.bmp", "Picture//PE//PE 007.bmp", "Picture//PE//PE 008.bmp", "Picture//PE//PE 009.bmp", "Picture//PE//PE 010.bmp","Picture//PE//PE 011.bmp", "Picture//PE//PE 012.bmp", "Picture//PE//PE 013.bmp", "Picture//PE//PE 014.bmp", "Picture//PE//PE 015.bmp", "Picture//PE//PE 016.bmp", "Picture//PE//PE 017.bmp", "Picture//PE//PE 018.bmp", "Picture//PE//PE 019.bmp", "Picture//PE//PE 020.bmp",
"Picture//PE//PE 021.bmp","Picture//PE//PE 022.bmp", "Picture//PE//PE 023.bmp", "Picture//PE//PE 024.bmp", "Picture//PE//PE 025.bmp", "Picture//PE//PE 026.bmp", "Picture//PE//PE 027.bmp", "Picture//PE//PE 028.bmp", "Picture//PE//PE 029.bmp", "Picture//PE//PE 030.bmp","Picture//PE//PE 031.bmp","Picture//PE//PE 032.bmp", "Picture//PE//PE 033.bmp", "Picture//PE//PE 034.bmp", "Picture//PE//PE 035.bmp", "Picture//PE//PE 036.bmp", "Picture//PE//PE 037.bmp", "Picture//PE//PE 038.bmp", "Picture//PE//PE 039.bmp", "Picture//PE//PE 040.bmp",
"Picture//PE//PE 041.bmp","Picture//PE//PE 042.bmp", "Picture//PE//PE 043.bmp", "Picture//PE//PE 044.bmp", "Picture//PE//PE 045.bmp", "Picture//PE//PE 046.bmp", "Picture//PE//PE 047.bmp", "Picture//PE//PE 048.bmp", "Picture//PE//PE 049.bmp", "Picture//PE//PE 050.bmp","Picture//PE//PE 051.bmp","Picture//PE//PE 052.bmp", "Picture//PE//PE 053.bmp", "Picture//PE//PE 054.bmp", "Picture//PE//PE 055.bmp", "Picture//PE//PE 056.bmp", "Picture//PE//PE 057.bmp", "Picture//PE//PE 058.bmp", "Picture//PE//PE 059.bmp", "Picture//PE//PE 060.bmp",
"Picture//PE//PE 061.bmp","Picture//PE//PE 062.bmp", "Picture//PE//PE 063.bmp", "Picture//PE//PE 064.bmp", "Picture//PE//PE 065.bmp", "Picture//PE//PE 066.bmp", "Picture//PE//PE 067.bmp", "Picture//PE//PE 068.bmp", "Picture//PE//PE 069.bmp", "Picture//PE//PE 070.bmp","Picture//PE//PE 071.bmp","Picture//PE//PE 072.bmp", "Picture//PE//PE 073.bmp", "Picture//PE//PE 074.bmp", "Picture//PE//PE 075.bmp", "Picture//PE//PE 076.bmp", "Picture//PE//PE 077.bmp", "Picture//PE//PE 078.bmp", "Picture//PE//PE 079.bmp", "Picture//PE//PE 080.bmp",
"Picture//PE//PE 081.bmp","Picture//PE//PE 082.bmp", "Picture//PE//PE 083.bmp", "Picture//PE//PE 084.bmp", "Picture//PE//PE 085.bmp", "Picture//PE//PE 086.bmp", "Picture//PE//PE 087.bmp", "Picture//PE//PE 088.bmp", "Picture//PE//PE 089.bmp", "Picture//PE//PE 090.bmp","Picture//PE//PE 091.bmp","Picture//PE//PE 092.bmp", "Picture//PE//PE 093.bmp", "Picture//PE//PE 094.bmp", "Picture//PE//PE 095.bmp", "Picture//PE//PE 096.bmp", "Picture//PE//PE 097.bmp", "Picture//PE//PE 098.bmp", "Picture//PE//PE 099.bmp", "Picture//PE//PE 100.bmp",
"Picture//PE//PE 101.bmp","Picture//PE//PE 102.bmp", "Picture//PE//PE 103.bmp", "Picture//PE//PE 104.bmp", "Picture//PE//PE 105.bmp", "Picture//PE//PE 106.bmp", "Picture//PE//PE 107.bmp", "Picture//PE//PE 108.bmp", "Picture//PE//PE 109.bmp", "Picture//PE//PE 110.bmp","Picture//PE//PE 111.bmp","Picture//PE//PE 112.bmp", "Picture//PE//PE 113.bmp", "Picture//PE//PE 114.bmp", "Picture//PE//PE 115.bmp", "Picture//PE//PE 116.bmp", "Picture//PE//PE 117.bmp", "Picture//PE//PE 118.bmp", "Picture//PE//PE 119.bmp", "Picture//PE//PE 120.bmp",
"Picture//PE//PE 121.bmp","Picture//PE//PE 122.bmp", "Picture//PE//PE 123.bmp", "Picture//PE//PE 124.bmp", "Picture//PE//PE 125.bmp", "Picture//PE//PE 126.bmp", "Picture//PE//PE 127.bmp", "Picture//PE//PE 128.bmp", "Picture//PE//PE 129.bmp", "Picture//PE//PE 130.bmp","Picture//PE//PE 131.bmp","Picture//PE//PE 132.bmp", "Picture//PE//PE 133.bmp", "Picture//PE//PE 134.bmp", "Picture//PE//PE 135.bmp", "Picture//PE//PE 136.bmp", "Picture//PE//PE 137.bmp", "Picture//PE//PE 138.bmp", "Picture//PE//PE 139.bmp", "Picture//PE//PE 140.bmp",
"Picture//PE//PE 141.bmp","Picture//PE//PE 142.bmp", "Picture//PE//PE 143.bmp", "Picture//PE//PE 144.bmp", "Picture//PE//PE 145.bmp", "Picture//PE//PE 146.bmp", "Picture//PE//PE 147.bmp", "Picture//PE//PE 148.bmp", "Picture//PE//PE 149.bmp", "Picture//PE//PE 150.bmp","Picture//PE//PE 151.bmp","Picture//PE//PE 152.bmp", "Picture//PE//PE 153.bmp", "Picture//PE//PE 154.bmp", "Picture//PE//PE 155.bmp", "Picture//PE//PE 156.bmp", "Picture//PE//PE 157.bmp", "Picture//PE//PE 158.bmp", "Picture//PE//PE 159.bmp", "Picture//PE//PE 160.bmp",
"Picture//PE//PE 161.bmp","Picture//PE//PE 162.bmp", "Picture//PE//PE 163.bmp", "Picture//PE//PE 164.bmp", "Picture//PE//PE 165.bmp", "Picture//PE//PE 166.bmp", "Picture//PE//PE 167.bmp", "Picture//PE//PE 168.bmp", "Picture//PE//PE 169.bmp", "Picture//PE//PE 170.bmp","Picture//PE//PE 171.bmp","Picture//PE//PE 172.bmp", "Picture//PE//PE 173.bmp", "Picture//PE//PE 174.bmp", "Picture//PE//PE 175.bmp", "Picture//PE//PE 176.bmp", "Picture//PE//PE 177.bmp", "Picture//PE//PE 178.bmp", "Picture//PE//PE 179.bmp", "Picture//PE//PE 180.bmp",
"Picture//PE//PE 181.bmp","Picture//PE//PE 182.bmp", "Picture//PE//PE 183.bmp", "Picture//PE//PE 184.bmp", "Picture//PE//PE 185.bmp", "Picture//PE//PE 186.bmp", "Picture//PE//PE 187.bmp", "Picture//PE//PE 188.bmp", "Picture//PE//PE 189.bmp", "Picture//PE//PE 190.bmp","Picture//PE//PE 191.bmp","Picture//PE//PE 192.bmp", "Picture//PE//PE 193.bmp", "Picture//PE//PE 194.bmp", "Picture//PE//PE 195.bmp", "Picture//PE//PE 196.bmp", "Picture//PE//PE 197.bmp", "Picture//PE//PE 198.bmp", "Picture//PE//PE 199.bmp", "Picture//PE//PE 200.bmp",
"Picture//PE//PE 201.bmp","Picture//PE//PE 202.bmp", "Picture//PE//PE 203.bmp", "Picture//PE//PE 204.bmp", "Picture//PE//PE 205.bmp", "Picture//PE//PE 206.bmp", "Picture//PE//PE 207.bmp", "Picture//PE//PE 208.bmp", "Picture//PE//PE 209.bmp", "Picture//PE//PE 210.bmp","Picture//PE//PE 211.bmp","Picture//PE//PE 212.bmp", "Picture//PE//PE 213.bmp", "Picture//PE//PE 214.bmp", "Picture//PE//PE 215.bmp", "Picture//PE//PE 216.bmp", "Picture//PE//PE 217.bmp", "Picture//PE//PE 218.bmp", "Picture//PE//PE 219.bmp", "Picture//PE//PE 220.bmp",
"Picture//PE//PE 221.bmp","Picture//PE//PE 222.bmp", "Picture//PE//PE 223.bmp", "Picture//PE//PE 224.bmp", "Picture//PE//PE 225.bmp", "Picture//PE//PE 226.bmp", "Picture//PE//PE 227.bmp", "Picture//PE//PE 228.bmp", "Picture//PE//PE 229.bmp", "Picture//PE//PE 230.bmp","Picture//PE//PE 231.bmp","Picture//PE//PE 232.bmp", "Picture//PE//PE 233.bmp", "Picture//PE//PE 234.bmp", "Picture//PE//PE 235.bmp", "Picture//PE//PE 236.bmp", "Picture//PE//PE 237.bmp", "Picture//PE//PE 238.bmp", "Picture//PE//PE 239.bmp", "Picture//PE//PE 240.bmp",
"Picture//PE//PE 241.bmp","Picture//PE//PE 242.bmp", "Picture//PE//PE 243.bmp", "Picture//PE//PE 244.bmp", "Picture//PE//PE 245.bmp", "Picture//PE//PE 246.bmp", "Picture//PE//PE 247.bmp", "Picture//PE//PE 248.bmp", "Picture//PE//PE 249.bmp", "Picture//PE//PE 250.bmp","Picture//PE//PE 251.bmp","Picture//PE//PE 252.bmp", "Picture//PE//PE 253.bmp", "Picture//PE//PE 254.bmp", "Picture//PE//PE 255.bmp", "Picture//PE//PE 256.bmp", "Picture//PE//PE 257.bmp", "Picture//PE//PE 258.bmp", "Picture//PE//PE 259.bmp", "Picture//PE//PE 260.bmp",
"Picture//PE//PE 261.bmp","Picture//PE//PE 262.bmp", "Picture//PE//PE 263.bmp", "Picture//PE//PE 264.bmp", "Picture//PE//PE 265.bmp", "Picture//PE//PE 266.bmp", "Picture//PE//PE 267.bmp", "Picture//PE//PE 268.bmp", "Picture//PE//PE 269.bmp", "Picture//PE//PE 270.bmp","Picture//PE//PE 271.bmp","Picture//PE//PE 272.bmp", "Picture//PE//PE 273.bmp", "Picture//PE//PE 274.bmp", "Picture//PE//PE 275.bmp", "Picture//PE//PE 276.bmp", "Picture//PE//PE 277.bmp", "Picture//PE//PE 278.bmp", "Picture//PE//PE 279.bmp", "Picture//PE//PE 280.bmp","Picture//PE//PE 281.bmp","Picture//PE//PE 282.bmp"};


char bonus[5][50] = { "Picture//booststatus.bmp", "Picture//coin.bmp", "Picture//health.bmp","Picture//shield.bmp","Picture//Speed1.bmp" };
char boostString[4][50] = { "Picture\\Boost\\boost1.bmp", "Picture\\Boost\\boost2.bmp", "Picture\\Boost\\boost3.bmp", "Picture\\Boost\\boost4.bmp"};
char blast[35][50] = { "Picture//Blast//blast1.bmp", "Picture//Blast//blast2.bmp", "Picture//Blast//blast3.bmp", "Picture//Blast//blast4.bmp", "Picture//Blast//blast5.bmp", "Picture//Blast//blast6.bmp", "Picture//Blast//blast7.bmp", "Picture//Blast//blast8.bmp", "Picture//Blast//blast9.bmp", "Picture//Blast//blast10.bmp", "Picture//Blast//blast11.bmp", "Picture//Blast//blast12.bmp", "Picture//Blast//blast13.bmp", "Picture//Blast//blast14.bmp", "Picture//Blast//blast15.bmp", "Picture//Blast//blast16.bmp", "Picture//Blast//blast17.bmp", "Picture//Blast//blast18.bmp", "Picture//Blast//blast19.bmp", "Picture//Blast//blast20.bmp", "Picture//Blast//blast21.bmp", "Picture//Blast//blast22.bmp", "Picture//Blast//blast23.bmp", "Picture//Blast//blast24.bmp", "Picture//Blast//blast25.bmp", "Picture//Blast//blast26.bmp", "Picture//Blast//blast27.bmp", "Picture//Blast//blast28.bmp", "Picture//Blast//blast29.bmp", "Picture//Blast//blast30.bmp", };
char anykey[5][50] = { "Picture//text.bmp", "Picture//text1.bmp", "Picture//text2.bmp", "Picture//text3.bmp", "Picture//text4.bmp" };
char button[5][50] = { "Picture//Button//start1.bmp", "Picture//Button//option1.bmp", "Picture//Button//leaderboard1.bmp", "Picture//Button//exit2.bmp" };
char introarray[300][50] = {"Picture//Intro//Intro  001.bmp", "Picture//Intro//Intro  002.bmp", "Picture//Intro//Intro  003.bmp", "Picture//Intro//Intro  004.bmp", "Picture//Intro//Intro  005.bmp", "Picture//Intro//Intro  006.bmp", "Picture//Intro//Intro  007.bmp", "Picture//Intro//Intro  008.bmp", "Picture//Intro//Intro  009.bmp", "Picture//Intro//Intro  010.bmp", "Picture//Intro//Intro  011.bmp", "Picture//Intro//Intro  012.bmp", "Picture//Intro//Intro  013.bmp", "Picture//Intro//Intro  014.bmp", "Picture//Intro//Intro  015.bmp", "Picture//Intro//Intro  016.bmp", "Picture//Intro//Intro  017.bmp", "Picture//Intro//Intro  018.bmp", "Picture//Intro//Intro  019.bmp", "Picture//Intro//Intro  020.bmp", "Picture//Intro//Intro  021.bmp", "Picture//Intro//Intro  022.bmp", "Picture//Intro//Intro  023.bmp", "Picture//Intro//Intro  024.bmp", "Picture//Intro//Intro  025.bmp", "Picture//Intro//Intro  026.bmp", "Picture//Intro//Intro  027.bmp", "Picture//Intro//Intro  028.bmp", "Picture//Intro//Intro  029.bmp", "Picture//Intro//Intro  030.bmp", "Picture//Intro//Intro  031.bmp", "Picture//Intro//Intro  032.bmp", "Picture//Intro//Intro  033.bmp", "Picture//Intro//Intro  034.bmp", "Picture//Intro//Intro  035.bmp", "Picture//Intro//Intro  036.bmp", "Picture//Intro//Intro  037.bmp", "Picture//Intro//Intro  038.bmp", "Picture//Intro//Intro  039.bmp", "Picture//Intro//Intro  040.bmp", "Picture//Intro//Intro  041.bmp", "Picture//Intro//Intro  042.bmp", "Picture//Intro//Intro  043.bmp", "Picture//Intro//Intro  044.bmp", "Picture//Intro//Intro  045.bmp", "Picture//Intro//Intro  046.bmp", "Picture//Intro//Intro  047.bmp", "Picture//Intro//Intro  048.bmp", "Picture//Intro//Intro  049.bmp", "Picture//Intro//Intro  050.bmp", "Picture//Intro//Intro  051.bmp", "Picture//Intro//Intro  052.bmp", "Picture//Intro//Intro  053.bmp", "Picture//Intro//Intro  054.bmp", "Picture//Intro//Intro  055.bmp", "Picture//Intro//Intro  056.bmp", "Picture//Intro//Intro  057.bmp", "Picture//Intro//Intro  058.bmp", "Picture//Intro//Intro  059.bmp", "Picture//Intro//Intro  060.bmp", "Picture//Intro//Intro  061.bmp", "Picture//Intro//Intro  062.bmp", "Picture//Intro//Intro  063.bmp", "Picture//Intro//Intro  064.bmp", "Picture//Intro//Intro  065.bmp", "Picture//Intro//Intro  066.bmp", "Picture//Intro//Intro  067.bmp", "Picture//Intro//Intro  068.bmp", "Picture//Intro//Intro  069.bmp", "Picture//Intro//Intro  070.bmp", "Picture//Intro//Intro  071.bmp", "Picture//Intro//Intro  072.bmp", "Picture//Intro//Intro  073.bmp", "Picture//Intro//Intro  074.bmp", "Picture//Intro//Intro  075.bmp", "Picture//Intro//Intro  076.bmp", "Picture//Intro//Intro  077.bmp", "Picture//Intro//Intro  078.bmp", "Picture//Intro//Intro  079.bmp", "Picture//Intro//Intro  080.bmp", "Picture//Intro//Intro  081.bmp", "Picture//Intro//Intro  082.bmp", "Picture//Intro//Intro  083.bmp", "Picture//Intro//Intro  084.bmp", "Picture//Intro//Intro  085.bmp", "Picture//Intro//Intro  086.bmp", "Picture//Intro//Intro  087.bmp", "Picture//Intro//Intro  088.bmp", "Picture//Intro//Intro  089.bmp", "Picture//Intro//Intro  090.bmp", "Picture//Intro//Intro  091.bmp", "Picture//Intro//Intro  092.bmp", "Picture//Intro//Intro  093.bmp", "Picture//Intro//Intro  094.bmp", "Picture//Intro//Intro  095.bmp", "Picture//Intro//Intro  096.bmp", "Picture//Intro//Intro  097.bmp", "Picture//Intro//Intro  098.bmp", "Picture//Intro//Intro  099.bmp", "Picture//Intro//Intro  100.bmp", "Picture//Intro//Intro  101.bmp", "Picture//Intro//Intro  102.bmp", "Picture//Intro//Intro  103.bmp", "Picture//Intro//Intro  104.bmp", "Picture//Intro//Intro  105.bmp", "Picture//Intro//Intro  106.bmp", "Picture//Intro//Intro  107.bmp", "Picture//Intro//Intro  108.bmp", "Picture//Intro//Intro  109.bmp", "Picture//Intro//Intro  110.bmp", "Picture//Intro//Intro  111.bmp", "Picture//Intro//Intro  112.bmp", "Picture//Intro//Intro  113.bmp", "Picture//Intro//Intro  114.bmp", "Picture//Intro//Intro  115.bmp", "Picture//Intro//Intro  116.bmp", "Picture//Intro//Intro  117.bmp", "Picture//Intro//Intro  118.bmp", "Picture//Intro//Intro  119.bmp", "Picture//Intro//Intro  120.bmp", "Picture//Intro//Intro  121.bmp", "Picture//Intro//Intro  122.bmp", "Picture//Intro//Intro  123.bmp", "Picture//Intro//Intro  124.bmp", "Picture//Intro//Intro  125.bmp", "Picture//Intro//Intro  126.bmp", "Picture//Intro//Intro  127.bmp", "Picture//Intro//Intro  128.bmp", "Picture//Intro//Intro  129.bmp", "Picture//Intro//Intro  130.bmp", "Picture//Intro//Intro  131.bmp", "Picture//Intro//Intro  132.bmp", "Picture//Intro//Intro  133.bmp", "Picture//Intro//Intro  134.bmp", "Picture//Intro//Intro  135.bmp", "Picture//Intro//Intro  136.bmp", "Picture//Intro//Intro  137.bmp", "Picture//Intro//Intro  138.bmp", "Picture//Intro//Intro  139.bmp", "Picture//Intro//Intro  140.bmp", "Picture//Intro//Intro  141.bmp", "Picture//Intro//Intro  142.bmp", "Picture//Intro//Intro  143.bmp", "Picture//Intro//Intro  144.bmp", "Picture//Intro//Intro  145.bmp", "Picture//Intro//Intro  146.bmp", "Picture//Intro//Intro  147.bmp", "Picture//Intro//Intro  148.bmp", "Picture//Intro//Intro  149.bmp", "Picture//Intro//Intro  150.bmp", "Picture//Intro//Intro  151.bmp", "Picture//Intro//Intro  152.bmp", "Picture//Intro//Intro  153.bmp", "Picture//Intro//Intro  154.bmp", "Picture//Intro//Intro  155.bmp", "Picture//Intro//Intro  156.bmp", "Picture//Intro//Intro  157.bmp", "Picture//Intro//Intro  158.bmp", "Picture//Intro//Intro  159.bmp", "Picture//Intro//Intro  160.bmp", "Picture//Intro//Intro  161.bmp", "Picture//Intro//Intro  162.bmp", "Picture//Intro//Intro  163.bmp", "Picture//Intro//Intro  164.bmp", "Picture//Intro//Intro  165.bmp", "Picture//Intro//Intro  166.bmp", "Picture//Intro//Intro  167.bmp", "Picture//Intro//Intro  168.bmp", "Picture//Intro//Intro  169.bmp", "Picture//Intro//Intro  170.bmp", "Picture//Intro//Intro  171.bmp", "Picture//Intro//Intro  172.bmp", "Picture//Intro//Intro  173.bmp", "Picture//Intro//Intro  174.bmp", "Picture//Intro//Intro  175.bmp", "Picture//Intro//Intro  176.bmp", "Picture//Intro//Intro  177.bmp", "Picture//Intro//Intro  178.bmp", "Picture//Intro//Intro  179.bmp", "Picture//Intro//Intro  180.bmp", "Picture//Intro//Intro  181.bmp", "Picture//Intro//Intro  182.bmp", "Picture//Intro//Intro  183.bmp", "Picture//Intro//Intro  184.bmp", "Picture//Intro//Intro  185.bmp", "Picture//Intro//Intro  186.bmp", "Picture//Intro//Intro  187.bmp", "Picture//Intro//Intro  188.bmp", "Picture//Intro//Intro  189.bmp", "Picture//Intro//Intro  190.bmp", "Picture//Intro//Intro  191.bmp", "Picture//Intro//Intro  192.bmp", "Picture//Intro//Intro  193.bmp", "Picture//Intro//Intro  194.bmp", "Picture//Intro//Intro  195.bmp", "Picture//Intro//Intro  196.bmp", "Picture//Intro//Intro  197.bmp", "Picture//Intro//Intro  198.bmp", "Picture//Intro//Intro  199.bmp", "Picture//Intro//Intro  200.bmp", "Picture//Intro//Intro  201.bmp", "Picture//Intro//Intro  202.bmp", "Picture//Intro//Intro  203.bmp", "Picture//Intro//Intro  204.bmp", "Picture//Intro//Intro  205.bmp", "Picture//Intro//Intro  206.bmp", "Picture//Intro//Intro  207.bmp", "Picture//Intro//Intro  208.bmp", "Picture//Intro//Intro  209.bmp", "Picture//Intro//Intro  210.bmp", "Picture//Intro//Intro  211.bmp", "Picture//Intro//Intro  212.bmp", "Picture//Intro//Intro  213.bmp", "Picture//Intro//Intro  214.bmp", "Picture//Intro//Intro  215.bmp", "Picture//Intro//Intro  216.bmp", "Picture//Intro//Intro  217.bmp", "Picture//Intro//Intro  218.bmp", "Picture//Intro//Intro  219.bmp", "Picture//Intro//Intro  220.bmp", "Picture//Intro//Intro  221.bmp", "Picture//Intro//Intro  222.bmp", "Picture//Intro//Intro  223.bmp", "Picture//Intro//Intro  224.bmp", "Picture//Intro//Intro  225.bmp", "Picture//Intro//Intro  226.bmp", "Picture//Intro//Intro  227.bmp", "Picture//Intro//Intro  228.bmp", "Picture//Intro//Intro  229.bmp", "Picture//Intro//Intro  230.bmp", "Picture//Intro//Intro  231.bmp", "Picture//Intro//Intro  232.bmp", "Picture//Intro//Intro  233.bmp", "Picture//Intro//Intro  234.bmp", "Picture//Intro//Intro  235.bmp", "Picture//Intro//Intro  236.bmp", "Picture//Intro//Intro  237.bmp", "Picture//Intro//Intro  238.bmp", "Picture//Intro//Intro  239.bmp", "Picture//Intro//Intro  240.bmp", "Picture//Intro//Intro  241.bmp", "Picture//Intro//Intro  242.bmp", "Picture//Intro//Intro  243.bmp", "Picture//Intro//Intro  244.bmp", "Picture//Intro//Intro  245.bmp", "Picture//Intro//Intro  246.bmp", "Picture//Intro//Intro  247.bmp", "Picture//Intro//Intro  248.bmp", "Picture//Intro//Intro  249.bmp", "Picture//Intro//Intro  250.bmp", "Picture//Intro//Intro  251.bmp", "Picture//Intro//Intro  252.bmp", "Picture//Intro//Intro  253.bmp", "Picture//Intro//Intro  254.bmp", "Picture//Intro//Intro  255.bmp", "Picture//Intro//Intro  256.bmp", "Picture//Intro//Intro  257.bmp", "Picture//Intro//Intro  258.bmp", "Picture//Intro//Intro  259.bmp", "Picture//Intro//Intro  260.bmp", "Picture//Intro//Intro  261.bmp", "Picture//Intro//Intro  262.bmp", "Picture//Intro//Intro  263.bmp", "Picture//Intro//Intro  264.bmp", "Picture//Intro//Intro  265.bmp", "Picture//Intro//Intro  266.bmp", "Picture//Intro//Intro  267.bmp", "Picture//Intro//Intro  268.bmp", "Picture//Intro//Intro  269.bmp", "Picture//Intro//Intro  270.bmp", "Picture//Intro//Intro  271.bmp", "Picture//Intro//Intro  272.bmp", "Picture//Intro//Intro  273.bmp", "Picture//Intro//Intro  274.bmp", "Picture//Intro//Intro  275.bmp", "Picture//Intro//Intro  276.bmp", "Picture//Intro//Intro  277.bmp", "Picture//Intro//Intro  278.bmp", "Picture//Intro//Intro  279.bmp", "Picture//Intro//Intro  280.bmp", "Picture//Intro//Intro  281.bmp", "Picture//Intro//Intro  282.bmp", "Picture//Intro//Intro  283.bmp", "Picture//Intro//Intro  284.bmp", "Picture//Intro//Intro  285.bmp", "Picture//Intro//Intro  286.bmp", "Picture//Intro//Intro  287.bmp", "Picture//Intro//Intro  288.bmp", "Picture//Intro//Intro  289.bmp", "Picture//Intro//Intro  290.bmp", "Picture//Intro//Intro  291.bmp", "Picture//Intro//Intro  292.bmp", "Picture//Intro//Intro  293.bmp", "Picture//Intro//Intro  294.bmp", "Picture//Intro//Intro  295.bmp", "Picture//Intro//Intro  296.bmp", "Picture//Intro//Intro  297.bmp", "Picture//Intro//Intro  298.bmp", "Picture//Intro//Intro  299.bmp", "Picture//Intro//Intro  300.bmp" };
char health[11][50] = { "Picture\\Health\\healthbar0.bmp", "Picture\\Health\\healthbar1.bmp", "Picture\\Health\\healthbar2.bmp", "Picture\\Health\\healthbar3.bmp", "Picture\\Health\\healthbar4.bmp", "Picture\\Health\\healthbar5.bmp", "Picture\\Health\\healthbar6.bmp", "Picture\\Health\\healthbar7.bmp", "Picture\\Health\\healthbar8.bmp", "Picture\\Health\\healthbar9.bmp", "Picture\\Health\\healthbar10.bmp" };
void iDraw()
{
	iClear();
	if (state == 1)
	{
		if (introdestroyed == true)
		{
			iShowBMP(0, 0, introdestroy[iindex]);
		}
		else
		{
			PlaySound(0, 0, 0);
			iShowBMP(0, 0, "Picture//background1.bmp");
			iShowBMP2(740, 250, "Picture//Button//start2.bmp", 0);
			iShowBMP2(740, 200, "Picture//Button//option2.bmp", 0);
			iShowBMP2(740, 150, "Picture//Button//leaderboard2.bmp", 0);
			iShowBMP2(740, 100, "Picture//Button//exit2.bmp", 0);
			if (frame == 0)
				iShowBMP2(740, 250, "Picture//Button//start1.bmp", 0);
			else if (frame == 1)
				iShowBMP2(740, 200, "Picture//Button//option1.bmp", 0);
			else if (frame == 2)
				iShowBMP2(740, 150, "Picture//Button//leaderboard1.bmp", 0);
			else if (frame == 3)
				iShowBMP2(740, 100, "Picture//Button//exit1.bmp", 0);
		}
	}
	else if (state == 0)
	{
		if (intro)
		{
			iClear();
			iShowBMP(0, 0, introarray[intro_counter]);
		}
		else if (intro == false)
		{
			iClear();
			iShowBMP(0, 0, "Picture//background.bmp");
			iShowBMP2(715, 50, anykey[i], 0);
		}
	}
	else if (state == 2)
	{
		iClear();
		option = fopen("Options.txt","r");
		for (optionIndex = 0; fscanf(option, "%s",options[optionIndex]) != EOF; optionIndex++);
		fclose(option);
		iShowBMP(0, 0, "Picture//blurbackground1.bmp");
		iShowBMP2(740, 970, "Picture//Button//option1.bmp", 0);
		iFilledRectangle(870, 980, 147, 5);
		iSetColor(225, 225, 225);
		iText(1000, 730, options[0] ,GLUT_BITMAP_TIMES_ROMAN_24 );
		iText(1000, 668, options[1], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1000, 609, options[2], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1000, 548, options[3], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1000, 490, options[4], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1000, 429, options[5], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1000, 367, options[6], GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(470, 700, "Picture//Button//up1.bmp", 0);
		iShowBMP2(490, 640, "Picture//Button//down1.bmp", 0);
		iShowBMP2(480, 580, "Picture//Button//left1.bmp", 0);
		iShowBMP2(490, 520, "Picture//Button//right1.bmp", 0);
		iShowBMP2(468, 460, "Picture//Button//ability1.bmp", 0);
		iShowBMP2(430, 400, "Picture//Button//pause1.bmp", 0);
		iShowBMP2(426, 340, "Picture//Button//boost1.bmp", 0);
		if (optionButton==1)
			iShowBMP2(471, 698, "Picture//Button//up.bmp", 0);
		else if(optionButton == 2)
			iShowBMP2(490, 640, "Picture//Button//down.bmp", 0);
		else if (optionButton==3)
			iShowBMP2(479, 578, "Picture//Button//left.bmp", 0);
		else if (optionButton==4)
			iShowBMP2(490, 520, "Picture//Button//right.bmp", 0);
		else if (optionButton==5)
			iShowBMP2(465, 400, "Picture//Button//ability.bmp", 0);
		else if (optionButton==6)
			iShowBMP2(426, 338, "Picture//Button//pause.bmp", 0);
		else if (optionButton==7)
			iShowBMP2(422, 278, "Picture//Button//boost.bmp", 0);
	}
	else if (state == 3)
	{
		iClear();
		iShowBMP(0, 0, "Picture//blurbackground1.bmp");
		fp = fopen("Leaderboard.txt", "r");
		for (scorePosition = 0; fscanf(fp, "%d", &score[scorePosition]) != EOF; scorePosition++);
		fclose(fp);
		sort(score, score + scorePosition);
		fp = fopen("Leaderboard.txt", "w");
		for (scorePosition = 0; scorePosition < 10; scorePosition++)
			fprintf(fp, "%d\n", score[scorePosition]);
		fclose(fp);
		fp = fopen("Leaderboard.txt", "r");
		for (scorePosition = 0; fscanf(fp, "%s", &score1[scorePosition]) && scorePosition < 10; scorePosition++);
		fclose(fp);
		iText(scorex-40, scorey, "1)", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(scorex, scorey, score1[9], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(scorex-40, scorey - 40, "2)", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(scorex, scorey - 40, score1[8], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(scorex-40, scorey - 80, "3)", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(scorex, scorey - 80, score1[7], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(scorex-40, scorey - 120, "4)", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(scorex, scorey - 120, score1[6], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(scorex-40, scorey - 160, "5)", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(scorex, scorey - 160, score1[5], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(scorex-40, scorey - 200, "6)", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(scorex, scorey - 200, score1[4], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(scorex-40, scorey - 240, "7)", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(scorex, scorey - 240, score1[3], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(scorex-40, scorey - 280, "8)", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(scorex, scorey - 280, score1[2], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(scorex-40, scorey - 320, "9)", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(scorex, scorey - 320, score1[1], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(scorex-40, scorey - 360, "10)", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(scorex, scorey - 360, score1[0], GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(740, 970, "Picture//Button//leaderboard1.bmp", 0);
		iFilledRectangle(815, 980, 252, 5);
		iSetColor(225, 225, 225);
	}
	else if (state == 4)
	{
		iClear();
		
			if (pause == true)
				iShowBMP2(650, 550, "Picture\\pause.bmp", 0);
			else
			{
				for (spaceI = 0; spaceI < backgroundPic; spaceI++)
				{
					iShowBMP(spaceBackground[spaceI].x, spaceBackground[spaceI].y, space[spaceI]);
				}
				if (bossstate == true)
				{
					if (playerx <= bossCox + 300 && playerx >= bossCox - 50 && playery >= bossCoy && shieldstatus==false)
						playerhealth = 0;
					if (checkfireBoss(bossCox, bossCoy))
					{
						if (bossHealthCounter == bossHealth)
						{
							bossstate = false;
							scoreplayer += bossHealthCounter;
							bossSpeed += 10;
							bossHealth += 240;
							bossHealthCounter = 0;
							bossCoy = 1080;
							iResumeTimer(t2);
						}
						bossHealthCounter++;
					}
					if (bossCoy<0)
					{
						bossfire[0].bossfirey = bossfire[1].bossfirey = bossfire[2].bossfirey = bossCoy;
						bomb1.bossfirey = bomb2.bossfirey = bossCoy;
						bossCoy = 1080;
						bossHorizontal = 0;
						bossHoriY = true;
						bossVertX = true;
						bossfire[1].bossfirex = bossCox + 170;
						bossfire[0].bossfirex = bossCox + 110;
						bossfire[2].bossfirex = bossCox + 230;
						bomb1.bossfirex = bossCox + 170;
						bomb2.bossfirex = bossCox + 230;

					}
					if (bossCoy > bossPosition)
					{
						iShowBMP2(bossCox, bossCoy-=bossSpeed, "Picture\\Enemy\\Boss1.bmp", 0);
					}
					else{

						if (bossHorizontal == 3)
						{
							if (bossCox < 1920 && bossVertX==true)
								iShowBMP2(bossCox += bossSpeed, bossCoy, "Picture\\Enemy\\Boss1.bmp", 0);
							else if (bossHoriY)
							{
								bossCoy = 1080;
								bossHoriY = false;
							}
							else
							{
								if (bossVertX)
								{
									bossCox = playerx-110;
									bossVertX = false;
								}
								iShowBMP2(bossCox, bossCoy -= bossSpeed, "Picture\\Enemy\\Boss1.bmp", 0);
							}
						}
						else
						{
							if (bossfireflag == true)
							{
								bossfire[1].bossfirex = bossCox+170;
								bossfire[0].bossfirex = bossCox + 110;
								bossfire[2].bossfirex = bossCox + 230;
								bossfire[0].bossfirey = bossfire[1].bossfirey = bossfire[2].bossfirey = bossCoy;
								bomb1.bossfirex = bossCox + 170;
								bomb2.bossfirex = bossCox + 230;
								bomb1.bossfirey = bomb2.bossfirey = bossCoy;
								bossfireflag = false;
							}
							else
							{
								bossfire[0].bossfirey = bossfire[1].bossfirey = bossfire[2].bossfirey -= bossfire[0].bossfirespeed;
								bomb1.bossfirey = bomb2.bossfirey -=bossfire[0].bossfirespeed;
								bomb1.bossfirex -= 15;
								bomb2.bossfirex += 15;
								if (bossfire[0].bossfirey <= 0 || bossfire[1].bossfirey <= 0 || bossfire[2].bossfirey <= 0)
								{
									bossfire[1].bossfirex = bossCox + 170;
									bossfire[0].bossfirex = bossCox + 110;
									bossfire[2].bossfirex = bossCox + 230;
									bossfire[0].bossfirey = bossfire[1].bossfirey = bossfire[2].bossfirey = bossCoy;
								}
								if (bomb1.bossfirey <= 0 || bomb2.bossfirey <= 0)
								{
									bomb1.bossfirex = bossCox + 170;
									bomb2.bossfirex = bossCox + 230;
									bomb1.bossfirey = bomb2.bossfirey = bossCoy;
								}
								iShowBMP2(bossfire[0].bossfirex, bossfire[0].bossfirey, "Picture\\bossfire.bmp", 0);
								iShowBMP2(bossfire[1].bossfirex, bossfire[1].bossfirey, "Picture\\bossfire.bmp", 0);
								iShowBMP2(bossfire[2].bossfirex, bossfire[2].bossfirey, "Picture\\bossfire.bmp", 0);
								iShowBMP2(bomb1.bossfirex, bomb1.bossfirey, "Picture\\BossBomb.bmp", 0);
								iShowBMP2(bomb2.bossfirex, bomb2.bossfirey, "Picture\\BossBomb.bmp", 0);
								if (bossfire[0].bossfirex >= playerx - 50 && bossfire[0].bossfirex <= playerx + 50 && bossfire[0].bossfirey >= playery - 50 && bossfire[0].bossfirey <= playery + 50)
								{
									if (shieldstatus==false)
									playerhealth -= reduce;
									bossfire[0].bossfirex = -1000;
								}
								if (bossfire[1].bossfirex >= playerx - 50 && bossfire[1].bossfirex <= playerx + 50 && bossfire[1].bossfirey >= playery - 50 && bossfire[1].bossfirey <= playery + 50)
								{
									if (shieldstatus == false)
									playerhealth -= reduce;
									bossfire[1].bossfirex = -1000;
								}
								if (bossfire[2].bossfirex >= playerx - 50 && bossfire[2].bossfirex <= playerx + 50 && bossfire[2].bossfirey >= playery - 50 && bossfire[2].bossfirey <= playery + 50)
								{
									if (shieldstatus == false)
									playerhealth -= reduce;
									bossfire[2].bossfirex = -1000;
								}
								if (bomb1.bossfirex >= playerx - 50 && bomb1.bossfirex <= playerx + 50 && bomb1.bossfirey >= playery - 50 && bomb1.bossfirey <= playery + 50)
								{
									if (shieldstatus == false)
									playerhealth -= 5;
									bomb1.bossfirex = -1000;
								}
								if (bomb2.bossfirex >= playerx - 50 && bomb2.bossfirex <= playerx + 50 && bomb2.bossfirey >= playery - 50 && bomb2.bossfirey <= playery + 50)
								{
									if (shieldstatus == false)
									playerhealth -= 5;
									bomb2.bossfirex = -1000;
								}

							}
							if (f1 == 0 && bossCox < 1550)
							{
								iShowBMP2(bossCox += bossSpeed, bossCoy, "Picture\\Enemy\\Boss1.bmp", 0);
								if (bossCox >= 1550)
								{
									f1 = 1;
									bossHorizontal++;
								}
							}
							else if (f1 == 1)
							{
								iShowBMP2(bossCox -= bossSpeed, bossCoy, "Picture\\Enemy\\Boss1.bmp", 0);
								if (bossCox <= 0)
									f1 = 0;
							}
						}
					}
				}

				else
				{
						iShowBMP2(b.bonx, b.bony, bonus[ind], 0);
						if (collitionbonus() == true)
						{
							if (ind == 2)
							{
								if (playerhealth <= 9)
								{
									playerhealth = playerhealth + 1;

								}
							}
							else if (ind == 1)
							{
								scoreplayer += 3;
							}
							else if (ind == 0)
							{
								if (boostMeter < 100)
								{
									boostMeter += 10;

								}
							}
							else if (ind == 3)
							{
								if (shield < 200)
								{
									shield += 50;
								}
							}
							if (ind == 4)
							{
								if (planespeed<10)
									planespeed += 2;
								if (planespeedcnt<5)
									planespeedcnt++;
							}
							b.bonx = 2000;
							bonuschange();
						}
						bonuschange();
						if (kalaenemyflag == 1)
						{
							iPauseTimer(t3);
						
							if (kalaenemyY >= 650)
							{
								kalaenemyY -= 10;
								iShowBMP2(kalaenemyX, kalaenemyY, "Picture\\Enemy\\enemy 4.bmp", 0);
							}
							else
							{
								if (checkfirekalaenemy(kalaenemyX, kalaenemyY) == true)
								{
									kalaheatcounter++;
									if (kalaheatcounter == 10)
									{
										scoreplayer += 10;
										kalaenemyflag = 0;
										kalaheatcounter = 0;
										kalaenemyY = 1900;
										kalaenemyfireflag = true;
										iResumeTimer(t3);
									}
								}
								if (kalaenemycollision(kalaenemyX, kalaenemyY) == true)
								{
									playerhealth = 0;
								}
								if (kalaenemyflag1 == 0 && kalaenemyX < 1500)
								{
									iShowBMP2(kalaenemyX += 10, kalaenemyY, "Picture\\Enemy\\enemy 4.bmp", 0);
									if (kalaenemyX >= 1500)
										kalaenemyflag1 = 1;
								}
								else if (kalaenemyflag1 == 1 && kalaenemyX > 0)
								{
									iShowBMP2(kalaenemyX -= 10, kalaenemyY, "Picture\\Enemy\\enemy 4.bmp", 0);
									if (kalaenemyX <= 0)
										kalaenemyflag1 = 0;
								}
								if (kalaenemyfirecollision(kalafire.kalafirex, kalafire.kalafirey))
								{
									if (!shieldstatus)
									{
										kalafire.kalafirex = 4000;
										playerhealth -= 2;
									}
									else
									{
										kalafire.kalafirex = 4000;
									}
								}
							}
							if (kalaenemyY <= 650)
							{
								if (kalaenemyfireflag == true)
								{
									kalafire.kalafirey = kalaenemyY;
									kalafire.kalafirex = kalaenemyX + 90;
									kalaenemyfireflag = false;
								}
								kalafire.kalafirey -= 20;
								if (kalafire.kalafirey <= 0 && kalaenemyfireflag==false)
								{
									kalafire.kalafirey = kalaenemyY;
									kalafire.kalafirex = kalaenemyX + 90;
								}
								iShowBMP2(kalafire.kalafirex, kalafire.kalafirey, "Picture\\kalaenemyfire.bmp", 0);
							}
							
						}
						for (eI2 = 0; eI2 <= numEnemy; eI2++)
						{
							counter = 0;
							for (int test = 0; test <= numEnemy; test++)
							{
								if (eShip[test].ePosY <= 0)
									counter++;
							}
							if (counter == numEnemy)
								enemySet();
							else
							{
								if (checkfire(eShip[eI2].ePosX, eShip[eI2].ePosY) == true)
								{
									eShip[eI2].ePosX = 2000;
									scoreplayer += 2;
								}
								if (enemycollision(eShip[eI2].ePosX, eShip[eI2].ePosY) == true && shieldstatus == false)
								{
									playerhealth--;
									eShip[eI2].ePosX = 2000;
								}
								if (eI2 == 0)
									iShowBMP2(eShip[eI2].ePosX, eShip[eI2].ePosY -= 5, "Picture\\Enemy\\enemy 2.bmp", 0);
								if (eI2 == 1)
									iShowBMP2(eShip[eI2].ePosX, eShip[eI2].ePosY -= 15, "Picture\\Enemy\\enemy 3.bmp", 0);
								if (eI2 == 2)
									iShowBMP2(eShip[eI2].ePosX, eShip[eI2].ePosY -= 25, "Picture\\Enemy\\enemy 5.bmp", 0);
								if (eI2 == 3)
									iShowBMP2(eShip[eI2].ePosX, eShip[eI2].ePosY -= 10, "Picture\\Enemy\\enemy 6.bmp", 0);
								if (eI2 == 4)
									iShowBMP2(eShip[eI2].ePosX, eShip[eI2].ePosY -= 20, "Picture\\Enemy\\enemy 7.bmp", 0);
							}
						}
						if (shieldstatus == true)
						{
							shield--;
							if (shield==0)
								shieldstatus=false;
						}
						if (collisioncheck() == false)
						{
							iShowBMP2(meteors.meteorx, meteors.meteory, "Picture//Meteors//meteor.bmp", 0);
							meteors.meteory -= meteorspeed;
							if (meteors.meteory <= 0)
							{
								if (meteors.meteorx>=0 && meteors.meteorx<=1920)
									earthhealth--;
								meteorchange();
							}
							if (earthhealth == 0)
							{
								state = 5;
								earthDestroyed = true;
							}
						}
						else
						{
							if (shieldstatus != true)
							{
								iShowBMP2(playerx + 12, playery + 5, "Picture//Blast//blast1.bmp", 0);
								meteors.meteorx = 2000;
								if (rand() % 15 <= 0)
									meteorspeed += 10;
								else
									meteorspeed = rand() % 15;
								playerhealth--;
							}

						}
						if (checkfiremeteor(meteors.meteorx, meteors.meteory) == true)
						{
							heatcounter++;
							if (heatcounter == 3)
							{
								meteors.meteorx = 2000;
								scoreplayer += 5;
								heatcounter = 0;
							}

						}
					}
					if (fireflag){
						if (fire1.firey >= 1080)
						{
							fire1.firey = playery;
							fire1.firex = playerx + 20;
						}
						if (fire2.firey >= 1080)
						{
							fire2.firey = playery;
							fire2.firex = playerx + 20;
						}
						if (fire3.firey >= 1080)
						{
							fire3.firey = playery;
							fire3.firex = playerx + 20;
						}
						if (fire4.firey >= 1080)
						{
							fire4.firey = playery;
							fire4.firex = playerx + 20;
						}
						if (fire5.firey >= 1080)
						{
							fire5.firey = playery;
							fire5.firex = playerx + 20;
						}
						if (fire6.firey >= 1080)
						{
							fire6.firey = playery;
							fire6.firex = playerx + 20;
						}
						if (fire7.firey >= 1080)
						{
							fire7.firey = playery;
							fire7.firex = playerx + 20;
						}
						if (fire8.firey >= 1080)
						{
							fire8.firey = playery;
							fire8.firex = playerx + 20;
						}
						if (fire9.firey >= 1080)
						{
							fire9.firey = playery;
							fire9.firex = playerx + 20;
						}
						if (fire10.firey >= 1080)
						{
							fire10.firey = playery;
							fire10.firex = playerx + 20;
						}
						if (fire11.firey >= 1080)
						{
							fire11.firey = playery;
							fire11.firex = playerx + 20;
						}
						if (fire12.firey >= 1080)
						{
							fire12.firey = playery;
							fire12.firex = playerx + 20;
						}
						if (fire13.firey >= 1080)
						{
							fire13.firey = playery;
							fire13.firex = playerx + 20;
						}
						if (fire14.firey >= 1080)
						{
							fire14.firey = playery;
							fire14.firex = playerx + 20;
						}
						if (fire15.firey >= 1080)
						{
							fire15.firey = playery;
							fire15.firex = playerx + 20;
						}
						if (fire16.firey >= 1080)
						{
							fire16.firey = playery;
							fire16.firex = playerx + 20;
						}
						if (fire17.firey >= 1080)
						{
							fire17.firey = playery;
							fire17.firex = playerx + 20;
						}
					}

				else
				{
					if (fire1.firey >= 2160)
					{
						fire1.firey = playery;
						fire1.firex = playerx + 20;
						FireCounter++;
					}
					if (fire2.firey >= 2160)
					{
						fire2.firey = playery;
						fire2.firex = playerx + 20;
						FireCounter++;
					}
					if (fire3.firey >= 2160)
					{
						fire3.firey = playery;
						fire3.firex = playerx + 20;
						FireCounter++;
					}
					if (fire4.firey >= 2160)
					{
						fire4.firey = playery;
						fire4.firex = playerx + 20;
						FireCounter++;
					}
					if (fire5.firey >= 2160)
					{
						fire5.firey = playery;
						fire5.firex = playerx + 20;
						FireCounter++;
					}
					if (fire6.firey >= 2160)
					{
						fire6.firey = playery;
						fire6.firex = playerx + 20;
						FireCounter++;
					}
					if (fire7.firey >= 2160)
					{
						fire7.firey = playery;
						fire7.firex = playerx + 20;
						FireCounter++;
					}
					if (fire8.firey >= 2160)
					{
						fire8.firey = playery;
						fire8.firex = playerx + 20;
						FireCounter++;
					}
					if (fire9.firey >= 2160)
					{
						fire9.firey = playery;
						fire9.firex = playerx + 20;
						FireCounter++;
					}
					if (fire10.firey >= 2160)
					{
						fire10.firey = playery;
						fire10.firex = playerx + 20;
						FireCounter++;
					}
					if (fire11.firey >= 2160)
					{
						fire11.firey = playery;
						fire11.firex = playerx + 20;
						FireCounter++;
					}
					if (fire12.firey >= 2160)
					{
						fire12.firey = playery;
						fire12.firex = playerx + 20;
						FireCounter++;
					}
					if (fire13.firey >= 2160)
					{
						fire13.firey = playery;
						fire13.firex = playerx + 20;
						FireCounter++;
					}
					if (fire14.firey >= 2160)
					{
						fire14.firey = playery;
						fire14.firex = playerx + 20;
						FireCounter++;
					}
					if (fire15.firey >= 2160)
					{
						fire15.firey = playery;
						fire15.firex = playerx + 20;
						FireCounter++;
					}
					if (fire16.firey >= 2160)
					{
						fire16.firey = playery;
						fire16.firex = playerx + 20;
						FireCounter++;
					}
					if (fire17.firey >= 2160)
					{
						fire17.firey = playery;
						fire17.firex = playerx + 20;
						FireCounter++;
					}
					if (FireCounter >= 16)
						fireflag = true;
				}
				iShowBMP2(fire1.firex, fire1.firey += 10, "Picture\\Fire\\fire1.bmp", 0);
				iShowBMP2(fire2.firex, fire2.firey += 10, "Picture\\Fire\\fire1.bmp", 0);
				iShowBMP2(fire3.firex, fire3.firey += 10, "Picture\\Fire\\fire1.bmp", 0);
				iShowBMP2(fire4.firex, fire4.firey += 10, "Picture\\Fire\\fire1.bmp", 0);
				iShowBMP2(fire5.firex, fire5.firey += 10, "Picture\\Fire\\fire1.bmp", 0);
				iShowBMP2(fire6.firex, fire6.firey += 10, "Picture\\Fire\\fire1.bmp", 0);
				iShowBMP2(fire7.firex, fire7.firey += 10, "Picture\\Fire\\fire1.bmp", 0);
				iShowBMP2(fire8.firex, fire8.firey += 10, "Picture\\Fire\\fire1.bmp", 0);
				iShowBMP2(fire9.firex, fire9.firey += 10, "Picture\\Fire\\fire1.bmp", 0);
				iShowBMP2(fire10.firex, fire10.firey += 10, "Picture\\Fire\\fire1.bmp", 0);
				iShowBMP2(fire11.firex, fire11.firey += 10, "Picture\\Fire\\fire1.bmp", 0);
				iShowBMP2(fire12.firex, fire12.firey += 10, "Picture\\Fire\\fire1.bmp", 0);
				iShowBMP2(fire13.firex, fire13.firey += 10, "Picture\\Fire\\fire1.bmp", 0);
				iShowBMP2(fire14.firex, fire14.firey += 10, "Picture\\Fire\\fire1.bmp", 0);
				iShowBMP2(fire15.firex, fire15.firey += 10, "Picture\\Fire\\fire1.bmp", 0);
				iShowBMP2(fire16.firex, fire16.firey += 10, "Picture\\Fire\\fire1.bmp", 0);
				iShowBMP2(fire17.firex, fire17.firey += 10, "Picture\\Fire\\fire1.bmp", 0);

				iShowBMP(0, 0, "Picture\\scoreBar.bmp");
				iText(20, 20, "Score :", GLUT_BITMAP_TIMES_ROMAN_24);
				_itoa(scoreplayer, score2, 10);
				iText(100, 19, score2, GLUT_BITMAP_TIMES_ROMAN_24);
				iShowBMP2(25, 110, "Picture\\playerHealth.bmp", 0);
				iShowBMP2(25, 50, "Picture\\earthHealth.bmp", 0);
				iText(120, 65, "%", GLUT_BITMAP_TIMES_ROMAN_24);
				iShowBMP2(265, 20, "Picture\\booststatus.bmp", 0);
				iShowBMP2(265, 100, "Picture\\firestatus.bmp", 0);
				_itoa(shield, shield1, 10);
				iText(330, 120,shield1, GLUT_BITMAP_TIMES_ROMAN_24);
				iShowBMP2(420, 100, "Picture\\Speed.bmp", 0);
				_itoa(planespeedcnt, planespeed1, 10);
				iText(490, 120, planespeed1, GLUT_BITMAP_TIMES_ROMAN_24);
				_itoa(boostMeter, boostmeter, 10);
				iText(330, 45, boostmeter, GLUT_BITMAP_TIMES_ROMAN_24);
				iText(370, 45, "%", GLUT_BITMAP_TIMES_ROMAN_24);
				iShowBMP2(85, 115, health[playerhealth], 0);
				_itoa(earthhealth, earth_health, 10);
				iText(85, 65, earth_health, GLUT_BITMAP_TIMES_ROMAN_24);
				if (boostMeter > 0 && booster == true)
				{
					for (int boostCounter = 1; boostCounter <= 4; boostCounter++)
					{
						iShowBMP2(playerx + 35, playery - 50, boostString[boostCounter-1], 0);
					}
					boostMeter--;
					scoreplayer++;
				}
				if (boostMeter == 0)
					booster = false;
				if (shieldstatus == true)
				{
					iShowBMP2(playerx-25, playery-30, "Picture\\shieldeffect.bmp", 0);
				}
				iShowBMP2(playerx, playery, "Picture\\Player\\player.bmp", 0);
				if (playerhealth <= 0)
				{
					iClear();
					iShowBMP2(playerx, playery, "Picture//Blast//blast22.bmp", 0);
					state = 5;
					playerDead = true;
				}
			}
			if (bossstate)
			{
				int bossLevel = bossHealth / 240;
				double tempo = bossHealth - bossHealthCounter;
				tempo /= (240*bossLevel);
				tempo *= 100;
				int bossLife = ceil(tempo); 
				if (bossLife<=80 && bossLife>65)
					iShowBMP(600, 50, "Picture//Bosshealth//bosshealth5.bmp");
				else if (bossLife <= 65 && bossLife >50)
					iShowBMP(600, 50, "Picture//Bosshealth//bosshealth4.bmp");
				else if (bossLife <= 50 && bossLife >25)
					iShowBMP(600, 50, "Picture//Bosshealth//bosshealth3.bmp");
				else if (bossLife <= 25 && bossLife>10)
					iShowBMP(600, 50, "Picture//Bosshealth//bosshealth2.bmp");
				else if (bossLife <= 10)
					iShowBMP(600, 50, "Picture//Bosshealth//bosshealth1.bmp");
				else if (bossLife> 80)
					iShowBMP(600, 50, "Picture//Bosshealth//bosshealth6.bmp");
			}
			
	}
	else if (state == 5)
	{
		iClear();
		iPauseTimer(t1);
		if (playerDead == true)
		{
			if (!pdestroystate)
			{
				iShowBMP(0, 0, "Picture\\destroyedplayer.bmp");
				iText(200, 200, "The player desparately tried to stop the enemy, at the last moment of his destruction. He self destructed taking down as many enemy as he could.", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else
			{
				iShowBMP(0, 0, pdestroy[pindex]);
			}
		}
		else if (earthDestroyed == true)
		{
			if (edestroystate == false)
			{
				iShowBMP(0, 0, "Picture\\destroyedearth.bmp");
				iText(200, 200, "The earth at it's last leg, soon to be destroyed completely as the very few survivors blaming fate and wondering what they could have done to change their fate.", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else
			{
				iShowBMP(0, 0, edestroy[eindex]);
			}
		}
	}
	else if (state == 6)
	{
		iClear();
		PlaySound(0, 0, 0);
		iShowBMP(500,550, "Picture\\Ending 1.bmp");
		iText(800, 500, "SCORE : ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(910, 500, score2 , GLUT_BITMAP_TIMES_ROMAN_24);
		fp = fopen("Leaderboard.txt", "r");
		for (scorePosition = 0; fscanf(fp, "%d", &score[scorePosition]) != EOF; scorePosition++);
		fclose(fp);
		if (scoreplayer > score[9])
			iText(800, 600, "Congratulations you achieved highest score!!", GLUT_BITMAP_TIMES_ROMAN_24);
		else if (scoreplayer < score[0])
			iText(800, 600, "TRY HARDER NEXT TIME", GLUT_BITMAP_TIMES_ROMAN_24);
		else
			iText(800, 600, "HIGH SCORER", GLUT_BITMAP_TIMES_ROMAN_24);
		for (scorePosition = 0; scorePosition < 10; scorePosition++)
		{
			if (scoreplayer >= score[scorePosition])
			{
				score[scorePosition] = scoreplayer;
				break;
			}
		}
		fp = fopen("Leaderboard.txt", "w");
		for (scorePosition = 0; scorePosition < 10; scorePosition++)
			fprintf(fp, "%d\n", score[scorePosition]);
		fclose(fp);
	}
}


void bossstatechange()
{
	bossstate = true;
	iPauseTimer(t2);
}
void ichange()
{
	if (iindex == 1286)
	{
		introdestroyed = false;
	}
	iindex++;
}
void scorechange()
{
	scoreplayer += 1;
}


void iMouseMove(int mx, int my)
{

}
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (mx >= 833 && mx <= 1065)
		{
			//button = 1;
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
void iPassiveMouseMove(int mx, int my)
{

	buttonposx = mx;
	buttonposy = my;
}


void kala()
{
	kalaenemyflag = 1;
}
void echange();

void iKeyboard(unsigned char key)
{
	if (key >= 0 && key <= 255 && state ==0 && intro==false)
	{
		introdestroyed = true;
		PlaySound(0, 0, 0);
		PlaySound("Sound//Animation1.wav", NULL, SND_ASYNC);
		iSetTimer(5, ichange);
		state = 1;
	}
	else if (key == '\b' && state == 1 && introdestroyed==true)
	{
		introdestroyed = false;
	}
	else if (key >= 0 && key <= 255 && state == 5)
	{
		if (earthDestroyed == true)
		{
			edestroystate = true;
			iSetTimer(5, echange);
			if (soundflag == 0)
			{
				PlaySound("Sound//EarthExplosion.wav", NULL, SND_ASYNC);
				soundflag = 1;
			}
		}
		else
		{
			pdestroystate = true;
			iSetTimer(5, pchange);
			if (soundflag == 0)
			{
				PlaySound("Sound//PlayerExplosion.wav", NULL, SND_ASYNC);
				soundflag = 1;
			}
		}
	}
	else if (key == '\b' && state == 5)
	{
		state = 6;
	}
	else if (key >= 0 && key <= 255 && state == 6)
	{
		exit(0);
	}
	else if (state == 1 && key == '\r' && frame == 0 && introdestroyed==false)
	{
		state = 4;
		showAll();
		fire1.firex = playerx + 20;
		fire1.firey = playery + 1930;
		fire2.firex = playerx + 20;
		fire2.firey = playery + 1880;
		fire3.firex = playerx + 20;
		fire3.firey = playery + 1830;
		fire4.firex = playerx + 20;
		fire4.firey = playery + 1780;
		fire5.firex = playerx + 20;
		fire5.firey = playery + 1730;
		fire6.firex = playerx + 20;
		fire6.firey = playery + 1680;
		fire7.firex = playerx + 20;
		fire7.firey = playery + 1630;
		fire8.firex = playerx + 20;
		fire8.firey = playery + 1580;
		fire9.firex = playerx + 20;
		fire9.firey = playery + 1530;
		fire10.firex = playerx + 20;
		fire10.firey = playery + 1480;
		fire11.firex = playerx + 20;
		fire11.firey = playery + 1430;
		fire12.firex = playerx + 20;
		fire12.firey = playery + 1380;
		fire13.firex = playerx + 20;
		fire13.firey = playery + 1280;
		fire14.firex = playerx + 20;
		fire14.firey = playery + 1230;
		fire15.firex = playerx + 20;
		fire15.firey = playery + 1180;
		fire16.firex = playerx + 20;
		fire16.firey = playery+ 1130;
		fire17.firex = playerx + 20;
		fire17.firey = playery+ 1080;

		iSetTimer(25, change1);
		t1=iSetTimer(1000, scorechange);
		t3=iSetTimer(20000, kala);
		t2= iSetTimer(60000, bossstatechange);
		meteors.meteory = 1080;
		eShip[0].ePosX = rand() % 1890;
		eShip[1].ePosX = rand() % 1890;
		eShip[2].ePosX = rand() % 1890;
		eShip[3].ePosX = rand() % 1890;
		eShip[5].ePosX = rand() % 1890;
		meteors.meteorx = rand() % 1890;
	}
	else if (state == 1 && key == '\r' && frame == 3 && introdestroyed==false)
	{
		exit(0);
	}
	else if (state == 1 && (frame == 1 || frame == 2) && key == '\r' && introdestroyed==false)
	{
		if (frame == 1)
			state = 2;
		else if (frame == 2)
			state = 3;
	}
	else if (key == 27 && (state == 2 || state ==3))
	{
		state = 1;
		optionButton = -2;
	}
	else if (key == 'p' && state == 4)
	{
		if (pause == false)
		{
			pause = true;
			iPauseTimer(t);
			iPauseTimer(t1);
			iShowBMP2(500, 500, "Picture\\pause.bmp", 0);
		}
		else if (pause==true)
		{
			pause = false;
			iResumeTimer(t);
			iResumeTimer(t1);
		}
	}
	else if (state == 4 && playerDead == false && earthDestroyed == false && key == ' ' && boostMeter > 0)
	{
		booster = true;
	}
	 if (state == 4 && shieldstatus == false && key=='x' && shield==200)
	{
			shieldstatus = true;
	}
}

void iSpecialKeyboard(unsigned char key)
{

	if (state == 1 && (key == GLUT_KEY_UP) || (key == GLUT_KEY_DOWN))
	{
		if (key == GLUT_KEY_DOWN)
		{
			frame++;
			if (frame == 4)
				frame = 0;
		}
		else if (key == GLUT_KEY_UP)
		{
			frame--;
			if (frame == -1)
				frame = 3;
		}

	}
	if (state == 2 && (key == GLUT_KEY_UP) || (key == GLUT_KEY_DOWN))
	{
		if (key == GLUT_KEY_DOWN)
		{
			optionButton++;
			if (optionButton==9)
				optionButton=1;
		}
		else if (key == GLUT_KEY_UP)
		{
			optionButton--;
			if (optionButton == 0)
				optionButton = 8;
		}
	}
	if (state == 4)
	{
		if (key == GLUT_KEY_RIGHT)
		{
			if (playerx <= 1780)
				playerx += (40+planespeed);
		}
		else if (key == GLUT_KEY_LEFT)
		{
			if (playerx >= 30)
				playerx -= (40 + planespeed);
		}
		else if (key == GLUT_KEY_UP)
		{
			if (playery<=940)
				playery += (40 + planespeed);
		}
		else if (key == GLUT_KEY_DOWN)
		{
			if (playery>=200)
				playery -= (40 + planespeed);
		}
	}

}
void change()
{
	if (f == 0)
	{
		if (i == 4)
			f = 1;
		else
			i++;
	}
	else
	{
		if (i == 0)
			f = 0;
		else
			i--;
	}

}
void introChange()
{
	if (intro_counter == 299)
	{
		intro = false;
		if (intro == false)
		{
			iSetTimer(100, change);
			PlaySound(0, 0, 0);
			PlaySound("Sound//loadingmusic.wav", NULL, SND_LOOP | SND_ASYNC);
		}
	}
	intro_counter++;
}
void echange()
{
	if (eindex == 478)
	{
		state = 6;
	}
	eindex++;
}
void pchange()
{
	if (pindex==281)
	{
		state = 6;
	}
	pindex++;
}