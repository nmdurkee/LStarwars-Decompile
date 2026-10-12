/* Ghidra pseudocode, not original source.
 * ev_0e37ff2b068f2f451a629821c3494056628992f54992bdfe8536c4096373c130
 * Entry: 0x4e9800; label: FUN_004e9800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e9800(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  _DAT_0095df36 = FUN_005806f0("trooper_green",param_1);
  _DAT_0095df34 = FUN_005806f0("trooper_red",param_1);
  DAT_0095df3c = 0;
  DAT_0095df3d = 0;
  DAT_0095df3e = 0;
  DAT_0095df3f = 0;
  DAT_0095df40 = 0;
  DAT_0095df41 = 1;
  DAT_0095df42 = 1;
  DAT_0095df43 = 1;
  DAT_0095df44 = 1;
  DAT_0095df45 = 1;
  FUN_005a8dd0(param_1,10,0x20,0);
  _memset(&DAT_0088a30c,0,0xbc);
  _DAT_0088a308 = 0;
  DAT_0088a300 = 0;
  DAT_0088a301 = 0;
  DAT_0088a302 = 1;
  DAT_0088a304 = 0xff;
  iVar1 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aad8,"minifig_1_1",1);
  iVar2 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aae4,"minifig_1_2",1);
  iVar3 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aaf0,"minifig_1_3",1);
  iVar4 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aafc,"minifig_2_1",1);
  iVar5 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087ab08,"minifig_2_2",1);
  iVar6 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087ab14,"minifig_2_3",1);
  if (iVar6 + iVar1 + iVar2 + iVar3 + iVar4 + iVar5 == 6) {
    DAT_0095df30 = &DAT_0087aad8;
  }
  if (DAT_00951b50 == 0) {
    FUN_004e90e0();
  }
  DAT_0088a244 = FUN_00578750(0x58);
  return;
}

