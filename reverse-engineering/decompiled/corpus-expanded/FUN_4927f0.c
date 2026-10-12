/* Ghidra pseudocode, not original source.
 * ev_f838318f8db109b6dcd3b75a6a424a1459b1413cbbc9987106adb019bff4cb04
 * Entry: 0x4927f0; label: FUN_004927f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004927f0(void)

{
  int iVar1;
  char cVar2;
  int unaff_ESI;
  uint uVar3;
  
  FUN_00564cd0();
  FUN_00401820();
  FUN_00595660(*(undefined4 *)(unaff_ESI + 0x2ab4),0x3f800000);
  FUN_00596960();
  if (DAT_00951be0 == 0) {
    FUN_0041d350();
  }
  FUN_00596a30();
  FUN_005d4290(1);
  FUN_0042df70();
  if (DAT_009506f0 == DAT_009506f4) {
    FUN_005ebd80(0x1f00,DAT_009506f0);
  }
  else {
    FUN_005feab0(0xf00,DAT_009506f0,DAT_009506f4,0x3f800000);
  }
  if (DAT_00951be0 == 0) {
    FUN_00596920(0);
    FUN_0064f5d0(DAT_0093b328);
    thunk_FUN_005d05b0();
    if (DAT_00951be0 == 0) {
      FUN_0041f660();
    }
  }
  FUN_00470940();
  FUN_00595660(*(undefined4 *)(unaff_ESI + 0x2ab4),0x3f800000);
  if ((DAT_0087b4d8 == 0) && (DAT_0093b328 == 0)) {
    if (DAT_00951be0 != 0) goto LAB_004928ea;
    FUN_00589f80();
    FUN_004b1ab0();
  }
  if (DAT_00951be0 == 0) {
    FUN_0058a270();
  }
LAB_004928ea:
  uVar3 = DAT_0093b2a0;
  if (DAT_00950744 == 0) {
    uVar3 = DAT_0093b328;
  }
  cVar2 = FUN_00565bf0();
  if (cVar2 != '\0') {
    uVar3 = 0;
  }
  if ((*(char *)(*(int *)(unaff_ESI + 0x2ac0) + 0x1e) != '\0') &&
     ((DAT_00951be0 == 0 || (DAT_00951c68 != 0)))) {
    FUN_00564c30(*(int *)(unaff_ESI + 0x2ac0) + 0x10);
  }
  if (DAT_00951be0 == 0) {
    FUN_0055f650();
    FUN_0057a560();
    FUN_005a1dd0();
    FUN_005a3cc0();
    FUN_00581bb0();
    FUN_0056e6a0();
    FUN_004d7fc0();
    FUN_00409980();
    FUN_00427070();
    FUN_00404dc0();
    FUN_004d4b00(*(undefined4 *)(unaff_ESI + 0x5168));
    FUN_00559d40(*(undefined4 *)(unaff_ESI + 0x2ac8));
    FUN_00571030();
    FUN_005452c0(0);
  }
  if (DAT_00947bbc != 0) {
    FUN_00546e60();
    FUN_00545c80();
  }
  (**(code **)(*DAT_0095e418 + 0x24))(0);
  FUN_0057d0a0();
  FUN_005fed10(DAT_00855f20);
  FUN_00608590(uVar3);
  iVar1 = *(int *)(unaff_ESI + 0x128);
  if ((((iVar1 == DAT_00951b88) || ((*(uint *)(iVar1 + 100) & 0x400) != 0)) ||
      (iVar1 == DAT_00951b9c)) || ((iVar1 == DAT_00951b98 && ((DAT_0087a6d8 & 0x400) != 0)))) {
    FUN_00564af0(0x3f800000,0);
  }
  if (_DAT_00950678 != 1.0) {
    FUN_00564af0(1.0 - _DAT_00950678,0);
  }
  FUN_005fecb0();
  FUN_00659280(DAT_00951c34);
  FUN_00685770(DAT_0087b4d8 ^ uVar3,1);
  FUN_005a2990(DAT_00876688);
  FUN_0042dff0();
  FUN_005f3950();
  FUN_00596870(DAT_0093b328);
  FUN_005d4290(1);
  FUN_00596520();
  FUN_004017b0();
  if (DAT_00805098 != 0) {
    FUN_0042fbf0(uVar3);
  }
  if (DAT_0087b560 != 0) {
    FUN_00491bd0(*(undefined4 *)(unaff_ESI + 0x13c));
  }
  FUN_005f3950();
  FUN_0060af80(uVar3,&DAT_0093d620);
  FUN_005d4290(1);
  FUN_00654fa0();
  FUN_00654ef0();
  FUN_00685770(DAT_0087b4d8 ^ uVar3,1);
  FUN_00685770(DAT_0087b4d8 ^ uVar3,0);
  FUN_005f39e0(0);
  FUN_006868f0();
  if (DAT_00950744 != 0) {
    return;
  }
  FUN_0040aa80();
  return;
}

