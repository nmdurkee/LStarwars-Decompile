/* Ghidra pseudocode, not original source.
 * ev_856f9c42d20ec6ba6350b0d1cce9335bfe45cee30263bcd63df252d3cb890b58
 * Entry: 0x528e00; label: FUN_00528e00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00528e00(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  undefined4 local_28;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_28;
  local_28 = param_1;
  if ((*(int *)(DAT_009238e4 + 0x371b0) != 0) &&
     (iVar1 = FUN_00619250(0xdc,0x46,0xf0,0xfa,DAT_02912e80,FUN_00528d00,"Activation Condition"),
     iVar1 != 0)) {
    uVar2 = FUN_00625240(1,&DAT_00801cb4,0,FUN_00528db0,1,9,
                         *(undefined1 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x8c),
                         "Activation Difficulty");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627b80(0,&DAT_00801cb4,*(char *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x8f) == '\0',
                         1,FUN_00528d10,"AUTOMATIC");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627b80(2,&DAT_00801cb4,
                         *(char *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x8f) == '\x02',1,FUN_00528d10
                         ,"SCRIPT");
    FUN_00618e10(iVar1,uVar2);
    iVar4 = 0;
    for (iVar3 = FUN_004f1440(DAT_009238e4 + 0x383c0); iVar3 != 0;
        iVar3 = FUN_004f1460(DAT_009238e4 + 0x383c0,iVar3)) {
      bVar5 = *(int *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x6c) == iVar3;
      _sprintf(local_24,"AREA \"%s\"",iVar3 + 8);
      uVar2 = FUN_00627b80(iVar4,&DAT_00801cb4,bVar5,1,FUN_00528d30,local_24);
      FUN_00618e10(iVar1,uVar2);
      if (bVar5) {
        *(undefined4 *)(iVar1 + 8) = DAT_02900c84;
      }
      FUN_006279b0(local_28,iVar1);
      iVar4 = iVar4 + 1;
    }
    FUN_006279b0(local_28,iVar1);
  }
  __security_check_cookie(local_4 ^ (uint)&local_28);
  return;
}

