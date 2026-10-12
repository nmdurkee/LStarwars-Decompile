/* Ghidra analysis pseudocode, not original source.
 * ev_9b402c9e9507e171b8c16fab1dff2f919b44cba00aab1d6e0da1cdd21bc5614e
 * Entry: 0x63f930; label: FUN_0063f930
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063f930(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x80000000;
  local_c = 0x800000ff;
  local_8 = 0x80808080;
  local_4 = 0x80f0f0f0;
  if (DAT_02913a20 == 0) {
    FUN_005d0a40(1);
    FUN_005d0fe0(DAT_009738b8,_DAT_0080fe00,_DAT_0080fe00);
    DAT_02913a20 = 1;
    FUN_006297f0();
    DAT_02913554 = FUN_00619250(100,0x46,0xb4,300,0,&LAB_006294d0,"Assoc ID");
    if (DAT_02913554 == 0) {
      FUN_00633df0();
    }
    iVar2 = 0;
    do {
      iVar3 = iVar2 + 1;
      uVar1 = FUN_00627bc0(iVar2,&local_10,0,iVar3,&LAB_00638cd0,(&PTR_DAT_0080fe20)[iVar2]);
      uVar1 = FUN_00618e10(DAT_02913554,uVar1);
      (&DAT_029137d0)[iVar2] = uVar1;
      iVar2 = iVar3;
    } while (iVar3 < 0x10);
    FUN_006242b0(DAT_02913554,5);
    DAT_0291381c = FUN_00619250(100,0x46,0xb4,300,0,&LAB_006294d0,"Exclude ID");
    if (DAT_0291381c == 0) {
      FUN_00633df0();
    }
    iVar2 = 0;
    do {
      iVar3 = iVar2 + 1;
      uVar1 = FUN_00627bc0(iVar2,&local_10,0,iVar3,&LAB_00638d20,(&PTR_DAT_0080fe20)[iVar2]);
      uVar1 = FUN_00618e10(DAT_0291381c,uVar1);
      (&DAT_02913850)[iVar2] = uVar1;
      iVar2 = iVar3;
    } while (iVar3 < 0x10);
    FUN_006242b0(DAT_0291381c,5);
    DAT_029137bc = FUN_00619250(100,0x46,0xb4,300,0,&LAB_006294d0,"User ID");
    if (DAT_029137bc == 0) {
      FUN_00633df0();
    }
    iVar2 = 0;
    do {
      uVar1 = FUN_00627b80(iVar2,&local_10,0,1,&LAB_00638d70,(&PTR_s_NO_ID_0080fe60)[iVar2]);
      uVar1 = FUN_00618e10(DAT_029137bc,uVar1);
      (&DAT_029135f8)[iVar2] = uVar1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x10);
    DAT_02913810 = FUN_00619250(100,0x46,0xb4,300,0,&LAB_006294d0,"Light Type");
    if (DAT_02913810 == 0) {
      FUN_00633df0();
    }
    uVar1 = FUN_00627b80(2,&local_10,0,2,&LAB_00638cb0,"Point");
    DAT_029137c0 = FUN_00618e10(DAT_02913810,uVar1);
    uVar1 = FUN_00627b80(8,&local_10,0,2,&LAB_00638cb0,"Jon Flicker");
    DAT_029134e4 = FUN_00618e10(DAT_02913810,uVar1);
    uVar1 = FUN_00627b80(3,&local_10,0,2,&LAB_00638cb0,"Point Flicker");
    DAT_029134a0 = FUN_00618e10(DAT_02913810,uVar1);
    uVar1 = FUN_00627b80(6,&local_10,0,2,&LAB_00638cb0,"Point Blend");
    DAT_0291363c = FUN_00618e10(DAT_02913810,uVar1);
    uVar1 = FUN_00627b80(1,&local_10,0,2,&LAB_00638cb0,"Ambient");
    DAT_029137b4 = FUN_00618e10(DAT_02913810,uVar1);
    uVar1 = FUN_00627b80(4,&local_10,0,2,&LAB_00638cb0,"Directional");
    DAT_029134b8 = FUN_00618e10(DAT_02913810,uVar1);
    uVar1 = FUN_00627b80(7,&local_10,0,2,&LAB_00638cb0,"Antilight");
    DAT_02913550 = FUN_00618e10(DAT_02913810,uVar1);
    uVar1 = FUN_00627b80(5,&local_10,0,2,&LAB_00638cb0,"Camdir");
    DAT_02913530 = FUN_00618e10(DAT_02913810,uVar1);
    FUN_006242b0(DAT_02913810,5);
    iVar2 = FUN_00619250(100,0x46,0xb4,300,0,&LAB_006294d0,"Modifiers");
    DAT_02913830 = iVar2;
    if (iVar2 == 0) {
      iVar2 = FUN_00633df0();
    }
    iVar3 = 0;
    if (0 < DAT_0080fe14) {
      do {
        uVar1 = FUN_00627b80(iVar3,&local_10,0,2,&LAB_00638b50,
                             *(undefined4 *)(PTR_PTR_0080fe10 + iVar3 * 4));
        uVar1 = FUN_00618e10(DAT_02913830,uVar1);
        (&DAT_02913698)[iVar3] = uVar1;
        iVar3 = iVar3 + 1;
        iVar2 = DAT_02913830;
      } while (iVar3 < DAT_0080fe14);
    }
    FUN_006242b0(iVar2,5);
    iVar2 = FUN_00619250(100,0x46,0xb4,300,0,&LAB_006294d0,"Adjust Modifiers");
    DAT_02913834 = iVar2;
    if (iVar2 == 0) {
      iVar2 = FUN_00633df0();
    }
    iVar3 = 0;
    if (0 < DAT_0080fe14) {
      do {
        uVar1 = FUN_00625150(iVar3,&local_10,0,&LAB_00638b70,0,0x3f800000,0x3f800000,
                             *(undefined4 *)(PTR_PTR_0080fe10 + iVar3 * 4));
        uVar1 = FUN_00618e10(DAT_02913834,uVar1);
        (&DAT_029138d0)[iVar3] = uVar1;
        FUN_0061d900(uVar1,0x3dcccccd);
        iVar3 = iVar3 + 1;
        iVar2 = DAT_02913834;
      } while (iVar3 < DAT_0080fe14);
    }
    FUN_006242b0(iVar2,5);
    DAT_02913638 = FUN_00619250(100,0x46,0xb4,300,0,&LAB_006294d0,"Flicker Light Options");
    if (DAT_02913638 == 0) {
      FUN_00633df0();
    }
    uVar1 = FUN_00627a80(0,&local_10,0,1,&LAB_00638c00,"Low Colour...");
    FUN_00618e10(DAT_02913638,uVar1);
    uVar1 = FUN_00625150(0,&local_10,0,&LAB_00638c30,0,0x40800000,0x40800000,"High Time");
    DAT_029134d0 = FUN_00618e10(DAT_02913638,uVar1);
    uVar1 = FUN_00625150(0,&local_10,0,&LAB_00638c50,0,0x40800000,0x40800000,"Random High Time");
    DAT_029134cc = FUN_00618e10(DAT_02913638,uVar1);
    uVar1 = FUN_00625150(0,&local_10,0,&LAB_00638c70,0,0x40800000,0x40800000,"Low Time");
    DAT_029134f4 = FUN_00618e10(DAT_02913638,uVar1);
    uVar1 = FUN_00625150(0,&local_10,0,&LAB_00638c90,0,0x40800000,0x40800000,"Random Low Time");
    DAT_02913498 = FUN_00618e10(DAT_02913638,uVar1);
    FUN_006242b0(DAT_02913638,5);
    DAT_029134d8 = FUN_00619250(100,0x46,0xb4,300,0,&LAB_006294d0,"Flicker Light Options");
    if (DAT_029134d8 == 0) {
      FUN_00633df0();
    }
    uVar1 = FUN_00627a80(0,&local_10,0,1,&LAB_00638c00,"Low Colour...");
    FUN_00618e10(DAT_029134d8,uVar1);
    uVar1 = FUN_00625150(0,&local_10,0,&LAB_00638c30,0,0x41200000,0x40800000,&DAT_0076c2b8);
    DAT_02913848 = FUN_00618e10(DAT_029134d8,uVar1);
    uVar1 = FUN_00625150(0,&local_10,0,&LAB_00638c50,0,0x41200000,0x40800000,"Random Step");
    DAT_0291371c = FUN_00618e10(DAT_029134d8,uVar1);
    uVar1 = FUN_00625150(0,&local_10,0,&LAB_00638c70,0,0x40800000,0x40800000,"Duration");
    DAT_02913898 = FUN_00618e10(DAT_029134d8,uVar1);
    FUN_006242b0(DAT_029134d8,5);
    DAT_029138b4 = FUN_00619250(100,0x46,0xb4,300,0,FUN_006395d0,"Light Properties");
    if (DAT_029138b4 == 0) {
      FUN_00633df0();
    }
    uVar1 = FUN_00627a80(DAT_02913810,&local_10,0,1,&LAB_00629480,"Type...");
    FUN_00618e10(DAT_029138b4,uVar1);
    uVar1 = FUN_00627a80(0,&local_10,0,1,&LAB_00638bd0,"Colour...");
    DAT_02913890 = FUN_00618e10(DAT_029138b4,uVar1);
    uVar1 = FUN_00627a80(DAT_02913638,&local_10,0,1,&LAB_00629480,"Flicker Light Options...");
    DAT_029138b8 = FUN_00618e10(DAT_029138b4,uVar1);
    uVar1 = FUN_00627a80(DAT_02913554,&local_10,0,1,&LAB_00629480,"Associate ID(s)...");
    _DAT_02913894 = FUN_00618e10(DAT_029138b4,uVar1);
    uVar1 = FUN_00627a80(DAT_0291381c,&local_10,0,1,&LAB_00629480,"Exclude ID(s)...");
    FUN_00618e10(DAT_029138b4,uVar1);
    uVar1 = FUN_00627a80(DAT_029137bc,&local_10,0,1,&LAB_00629480,"User ID...");
    FUN_00618e10(DAT_029138b4,uVar1);
    uVar1 = FUN_00625150(0,&local_10,0,&LAB_00638af0,0x3f000000,0x42fe0000,0x3f800000,"Multiplier");
    DAT_0291383c = FUN_00618e10(DAT_029138b4,uVar1);
    FUN_0061d900(DAT_0291383c,0x3dcccccd);
    FUN_0061d880(DAT_0291383c,&DAT_0076c220);
    uVar1 = FUN_00625240(0,&local_10,0,&LAB_00638b10,0,0xff,0,"Group ID");
    DAT_02913844 = FUN_00618e10(DAT_029138b4,uVar1);
    uVar1 = FUN_00627a80(DAT_02913830,&local_10,0,1,&LAB_00629480,"Modifier...");
    _DAT_0291349c = FUN_00618e10(DAT_029138b4,uVar1);
    uVar1 = FUN_00627bc0(0,&local_10,0,2,&LAB_00638b90,"Cast Shadow");
    DAT_029134b4 = FUN_00618e10(DAT_029138b4,uVar1);
    uVar1 = FUN_00627bc0(0,&local_10,0,3,&LAB_00638bb0,"Has Specular");
    DAT_0291354c = FUN_00618e10(DAT_029138b4,uVar1);
    FUN_006242b0(DAT_029138b4,5);
    DAT_029135e8 = FUN_00619250(100,0x46,0xb4,300,0,&LAB_006294d0,"Hide Lights");
    if (DAT_029135e8 == 0) {
      FUN_00633df0();
    }
    uVar1 = FUN_00627bc0(2,&local_10,0,1,&LAB_00639570,"Point");
    _DAT_029134d4 = FUN_00618e10(DAT_029135e8,uVar1);
    uVar1 = FUN_00627bc0(3,&local_10,0,2,&LAB_00639570,"Point Flicker");
    _DAT_02913500 = FUN_00618e10(DAT_029135e8,uVar1);
    uVar1 = FUN_00627bc0(6,&local_10,0,2,&LAB_00639570,"Point Blend");
    _DAT_02913820 = FUN_00618e10(DAT_029135e8,uVar1);
    uVar1 = FUN_00627bc0(1,&local_10,0,3,&LAB_00639570,"Ambient");
    _DAT_029137c8 = FUN_00618e10(DAT_029135e8,uVar1);
    uVar1 = FUN_00627bc0(4,&local_10,0,4,&LAB_00639570,"Directional");
    _DAT_029134f8 = FUN_00618e10(DAT_029135e8,uVar1);
    uVar1 = FUN_00627bc0(7,&local_10,0,4,&LAB_00639570,"Antilight");
    _DAT_029137b8 = FUN_00618e10(DAT_029135e8,uVar1);
    uVar1 = FUN_00627bc0(5,&local_10,0,4,&LAB_00639570,"Camdir");
    _DAT_02913504 = FUN_00618e10(DAT_029135e8,uVar1);
    FUN_006242b0(DAT_029135e8,5);
    DAT_029137b0 = FUN_00619250(100,0x46,0xb4,300,0,&LAB_00638230,"Delete Light?");
    if (DAT_029137b0 == 0) {
      FUN_00633df0();
    }
    uVar1 = FUN_00627a80(0,&local_10,0,1,&LAB_00638240,&PTR_DAT_0075f2d4);
    FUN_00618e10(DAT_029137b0,uVar1);
    uVar1 = FUN_00627a80(0,&local_10,0,1,&LAB_00638280,&DAT_0075f2d0);
    FUN_00618e10(DAT_029137b0,uVar1);
    FUN_006242b0(DAT_029137b0,5);
    DAT_02913534 = FUN_00619250(100,0x46,0xb4,300,0,&LAB_00638230,"Global Change Applied");
    if (DAT_02913534 == 0) {
      FUN_00633df0();
    }
    uVar1 = FUN_00627a80(0,&local_10,0,1,&LAB_006294e0,&DAT_0076c1bc);
    FUN_00618e10(DAT_02913534,uVar1);
    FUN_006242b0(DAT_02913534,5);
    DAT_02913548 = FUN_00619250(100,0x46,0xb4,300,0,&LAB_006294d0,"Global Adjustments");
    if (DAT_029138b4 == 0) {
      FUN_00633df0();
    }
    uVar1 = FUN_00625150(0,&local_10,0,0,0x40000000,0x41000000,0x40000000,"Scale Amount");
    DAT_02913538 = FUN_00618e10(DAT_02913548,uVar1);
    FUN_0061d900(DAT_02913538,0x3f800000);
    FUN_0061d880(DAT_02913538,&DAT_0076c190);
    uVar1 = FUN_00627a80(0,&local_10,0,1,&LAB_00639670,"Scale All Multipliers Up");
    FUN_00618e10(DAT_02913548,uVar1);
    uVar1 = FUN_00627a80(0,&local_10,0,1,&LAB_00639770,"Scale All Multipliers Down");
    FUN_00618e10(DAT_02913548,uVar1);
    FUN_006242b0(DAT_02913548,5);
    DAT_029134dc = FUN_00619250(100,0x46,0xb4,300,0,&LAB_006294d0,"Load lights?");
    if (DAT_029134dc == 0) {
      FUN_00633df0();
    }
    uVar1 = FUN_00627a80(0,&local_10,0,1,&LAB_006389c0,&PTR_DAT_0075f2d4);
    FUN_00618e10(DAT_029134dc,uVar1);
    uVar1 = FUN_00627a80(0,&local_10,0,1,&LAB_006294e0,&DAT_0075f2d0);
    FUN_00618e10(DAT_029134dc,uVar1);
    FUN_006242b0(DAT_029137b0,5);
    DAT_029137ac = FUN_00619250(100,0x46,0xb4,300,0,&LAB_00638220,"Light Editor Options");
    if (DAT_029137ac == 0) {
      FUN_00633df0();
    }
    uVar1 = FUN_00627a80(DAT_029138b4,&local_10,0,1,&DAT_006395b0,"Light Properties...");
    DAT_02913838 = FUN_00618e10(DAT_029137ac,uVar1);
    uVar1 = FUN_00627a80(0,&local_10,0,1,&LAB_00639130,&DAT_0076b028);
    DAT_029138bc = FUN_00618e10(DAT_029137ac,uVar1);
    uVar1 = FUN_00627a80(0,&local_10,0,1,0x639150,"Paste New");
    DAT_029137cc = FUN_00618e10(DAT_029137ac,uVar1);
    uVar1 = FUN_00627a80(0,&local_10,0,1,FUN_00639270,"Paste Into");
    DAT_0291382c = FUN_00618e10(DAT_029137ac,uVar1);
    uVar1 = FUN_00627a80(0,&local_10,0,1,FUN_006393b0,"Copy To Group");
    DAT_02913540 = FUN_00618e10(DAT_029137ac,uVar1);
    uVar1 = FUN_00627a80(0,&local_10,0,1,&LAB_0063f910,&DAT_0076c0ec);
    DAT_029137c4 = FUN_00618e10(DAT_029137ac,uVar1);
    uVar1 = FUN_00627a80(0,&local_10,0,1,&LAB_0063f920,&DAT_0076c0e4);
    DAT_02913508 = FUN_00618e10(DAT_029137ac,uVar1);
    *(byte *)(DAT_029137c4 + 0x11) = *(byte *)(DAT_029137c4 + 0x11) | 2;
    *(byte *)(DAT_02913508 + 0x11) = *(byte *)(DAT_02913508 + 0x11) | 2;
    uVar1 = FUN_00627bc0(0,&local_10,0,2,&LAB_00639590,"No Z Buffer");
    FUN_00618e10(DAT_029137ac,uVar1);
    uVar1 = FUN_00627bc0(0,&local_10,0,3,&LAB_006238e0,"Near Clip At Cursor");
    FUN_00618e10(DAT_029137ac,uVar1);
    uVar1 = FUN_00627a80(DAT_02913834,&local_10,0,1,&LAB_00629480,"Adjust Modifiers...");
    FUN_00618e10(DAT_029137ac,uVar1);
    uVar1 = FUN_00627a80(DAT_029135e8,&local_10,0,1,&LAB_00629480,"Hide Lights...");
    FUN_00618e10(DAT_029137ac,uVar1);
    uVar1 = FUN_00627a80(DAT_02913548,&local_10,0,1,&LAB_00629480,"Global Adjustments...");
    FUN_00618e10(DAT_029137ac,uVar1);
    uVar1 = FUN_00627a80(0,&local_10,0,1,&LAB_00638a70,"Save Lights/Fog");
    FUN_00618e10(DAT_029137ac,uVar1);
    uVar1 = FUN_00627a80(DAT_029134dc,&local_10,0,1,&LAB_00629480,"Load Lights/Fog");
    FUN_00618e10(DAT_029137ac,uVar1);
    uVar1 = FUN_00627b80(1,&local_10,1,4,&LAB_00639660,"Ralph Controls");
    FUN_00618e10(DAT_029137ac,uVar1);
    uVar1 = FUN_00627b80(0,&local_10,0,4,&LAB_00639660,"Steve Controls");
    FUN_00618e10(DAT_029137ac,uVar1);
    FUN_006242b0(DAT_029137ac,5);
    DAT_0291384c = FUN_00619250(100,0x46,0xb4,300,0,&LAB_006294d0,"Fog Settings");
    if (DAT_0291384c == 0) {
      FUN_00633df0();
    }
    uVar1 = FUN_00627a80(0,&local_10,0,1,&LAB_00638d90,"Fog Colour...");
    _DAT_029134b0 = FUN_00618e10(DAT_0291384c,uVar1);
    uVar1 = FUN_00625150(0,&local_10,0,&LAB_00638df0,0,0x43000000,0x3f800000,"Fog Density (alpha)");
    DAT_029138a0 = FUN_00618e10(DAT_0291384c,uVar1);
    uVar1 = FUN_00625150(0,&local_10,0,&LAB_00638e40,0,0x40800000,0x3f800000,"Fog Density (new)");
    DAT_029138a8 = FUN_00618e10(DAT_0291384c,uVar1);
    uVar1 = FUN_00625150(0,&local_10,0,&LAB_00638e60,0,0x40800000,0x3f800000,"Fog Density (Wii)");
    DAT_02913718 = FUN_00618e10(DAT_0291384c,uVar1);
    *(undefined4 *)(DAT_029138a8 + 0x68) = 0x37a7c5ac;
    uVar1 = FUN_00625150(0,&local_10,0,&LAB_00638f40,0,0x44fa0000,0x40800000,"Fog Start (PS2)");
    DAT_029134f0 = FUN_00618e10(DAT_0291384c,uVar1);
    uVar1 = FUN_00625150(0,&local_10,0,&LAB_00638f60,0,0x44fa0000,0x40800000,"Fog End (PS2)");
    DAT_029138a4 = FUN_00618e10(DAT_0291384c,uVar1);
    uVar1 = FUN_00625150(0,&local_10,0,&LAB_00638f00,0,0x44fa0000,0x40800000,"Fog Start (PSP)");
    DAT_02913544 = FUN_00618e10(DAT_0291384c,uVar1);
    uVar1 = FUN_00625150(0,&local_10,0,&LAB_00638f20,0,0x44fa0000,0x40800000,"Fog End (PSP)");
    iVar3 = FUN_00618e10(DAT_0291384c,uVar1);
    iVar2 = DAT_029138a4;
    *(undefined4 *)(DAT_029134f0 + 0x68) = 0x3e000000;
    DAT_029134ec = iVar3;
    *(undefined4 *)(iVar2 + 0x68) = 0x41200000;
    *(undefined4 *)(DAT_02913544 + 0x68) = 0x3e000000;
    *(undefined4 *)(iVar3 + 0x68) = 0x41200000;
    uVar1 = FUN_00627a80(0,&local_10,0,1,&LAB_00638dc0,"Haze Colour...");
    _DAT_029138ac = FUN_00618e10(DAT_0291384c,uVar1);
    uVar1 = FUN_00625150(0,&local_10,0,&LAB_00638e80,0,0x43000000,0x3f800000,"Haze Density");
    DAT_02913828 = FUN_00618e10(DAT_0291384c,uVar1);
    uVar1 = FUN_00625150(0,&local_10,0,&LAB_00638ed0,0,0x3f800000,0x3f800000,"Blur Density");
    DAT_029138c8 = FUN_00618e10(DAT_0291384c,uVar1);
    uVar1 = FUN_00625150(0,&local_10,0,&LAB_00638f80,0,0x44fa0000,0x447a0000,"Fog Distance Range");
    _DAT_029134e0 = FUN_00618e10(DAT_0291384c,uVar1);
    uVar1 = FUN_00625150(0,&local_10,0,&LAB_00639020,0x3a83126f,0x44fa0000,0x3dcccccd,
                         "Near Clip (editor only)");
    DAT_02913998 = FUN_00618e10(DAT_0291384c,uVar1);
    uVar1 = FUN_00625150(0,&local_10,0,&LAB_00639080,0x3a83126f,0x459c4000,0x447a0000,
                         "Far Clip (editor only)");
    DAT_0291399c = FUN_00618e10(DAT_0291384c,uVar1);
    uVar1 = FUN_00625150(0,&local_10,0,&LAB_006390e0,0x3f800000,0x41a80000,0x3f800000,"DOF - F-Stop"
                        );
    DAT_029138c4 = FUN_00618e10(DAT_0291384c,uVar1);
    iVar2 = DAT_0291384c;
    *(undefined4 *)(DAT_029138c4 + 0x68) = 0x3dcccccd;
    FUN_006242b0(iVar2,5);
    DAT_0291353c = FUN_00619250(100,0x46,0xb4,300,0,&LAB_00638220,"Fog Editor Options");
    if (DAT_029137ac == 0) {
      FUN_00633df0();
    }
    uVar1 = FUN_00627a80(DAT_0291384c,&local_10,0,1,&LAB_00629480,"Fog Settings...");
    DAT_02913840 = FUN_00618e10(DAT_0291353c,uVar1);
    uVar1 = FUN_00627a80(0,&local_10,0,1,&LAB_006394b0,&DAT_0076b028);
    DAT_02913640 = FUN_00618e10(DAT_0291353c,uVar1);
    uVar1 = FUN_00627a80(0,&local_10,0,1,&LAB_006394d0,"Paste New");
    DAT_02913644 = FUN_00618e10(DAT_0291353c,uVar1);
    uVar1 = FUN_00627a80(0,&local_10,0,1,&DAT_00639520,"Paste Into");
    DAT_029134c0 = FUN_00618e10(DAT_0291353c,uVar1);
    uVar1 = FUN_00627a80(0,&local_10,0,1,&LAB_00638a70,"Save Lights/Fog");
    FUN_00618e10(DAT_0291353c,uVar1);
    uVar1 = FUN_00627a80(0,&local_10,0,1,&LAB_006389c0,"Load Lights/Fog");
    FUN_00618e10(DAT_0291353c,uVar1);
    uVar1 = FUN_00627b80(1,&local_10,1,4,&LAB_00639660,"Ralph Controls");
    FUN_00618e10(DAT_0291353c,uVar1);
    uVar1 = FUN_00627b80(0,&local_10,0,4,&LAB_00639660,"Steve Controls");
    FUN_00618e10(DAT_0291353c,uVar1);
    FUN_006242b0(DAT_0291353c,5);
    FUN_005d0a70();
  }
  return;
}

