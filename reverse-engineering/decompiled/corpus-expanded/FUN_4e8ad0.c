/* Ghidra pseudocode, not original source.
 * ev_0e37ff2b068f2f451a629821c3494056628992f54992bdfe8536c4096373c130
 * Entry: 0x4e8ad0; label: FUN_004e8ad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e8ad0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 local_4 [4];
  
  DAT_0087aa5c = FUN_005aac00(DAT_0095df4c,"BombGen_ATAT_Killed",0);
  DAT_0087a9e0 = FUN_0051adf0(*(int *)(param_1 + 0x2ae8),
                              *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x2ae8) + 0x10) + 8),
                              "ice_a","ice_b",local_4);
  DAT_0087a96c = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802644,"obstacle3");
  DAT_0087a970 = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_008033a4,"m_pup7");
  FUN_005cfc00(&DAT_0087ab50,0);
  _DAT_0095df36 = FUN_005806f0("trooper_green",param_1);
  _DAT_0095df34 = FUN_005806f0("trooper_red",param_1);
  DAT_0095df3c = 0;
  DAT_0095df3d = 1;
  FUN_005a8dd0(param_1,2,0x20,0);
  iVar1 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aad8,"minifig_1_1",1);
  iVar2 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aae4,"minifig_1_2",1);
  iVar3 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aaf0,"minifig_1_3",1);
  iVar4 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aafc,"minifig_2_1",1);
  iVar5 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087ab08,"minifig_2_2",1);
  iVar6 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087ab14,"minifig_2_3",1);
  if (iVar6 + iVar1 + iVar2 + iVar3 + iVar4 + iVar5 == 6) {
    DAT_0095df30 = &DAT_0087aad8;
  }
  return;
}

