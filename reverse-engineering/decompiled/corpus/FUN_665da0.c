/* Ghidra analysis pseudocode, not original source.
 * ev_280130a43e77cd6b8822caba528fd01ad8a7c5be61051c42bd6bb5c51ef00c77
 * Entry: 0x665da0; label: FUN_00665da0
 */

void FUN_00665da0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  char local_14 [16];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_24;
  local_24 = 0x80000000;
  local_20 = 0x80ff0000;
  local_1c = 0x80808080;
  local_18 = 0x80404040;
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    DAT_02962a54 = FUN_00619250(0x46,0x46,0xfa,300,DAT_02912e80,&LAB_00665d80,"Attached Sounds");
    if (DAT_02962a54 != 0) {
      iVar3 = 0;
      do {
        iVar1 = iVar3 + 1;
        _sprintf(local_14,"Sound %d...",iVar1);
        uVar2 = FUN_00627a80(iVar3,&local_24,0,0,FUN_00665c50,local_14);
        FUN_00618e10(DAT_02962a54,uVar2);
        iVar3 = iVar1;
      } while (iVar1 < 4);
      FUN_006279b0(param_1,DAT_02962a54);
      *(int *)(DAT_02962a54 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_02962a54 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_24);
  return;
}

