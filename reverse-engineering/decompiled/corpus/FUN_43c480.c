/* Ghidra analysis pseudocode, not original source.
 * ev_22daf69c4a948facb72037c7642983d59ec5bfdbe162bc8de16c186a70e458b1
 * Entry: 0x43c480; label: FUN_0043c480
 */

void FUN_0043c480(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_14;
  undefined1 local_10 [4];
  undefined1 local_c [8];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_14;
  local_14 = param_1;
  if (((param_2 < 0xc) && (*(char **)(param_1 + 0x10) != (char *)0x0)) &&
     (iVar6 = 0, **(char **)(param_1 + 0x10) != '\0')) {
    do {
      iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x10) + 4) + iVar6 * 4);
      iVar8 = 0;
      if (*(short *)(iVar1 + 0x12) != 0) {
        iVar7 = 0;
        do {
          iVar5 = *(int *)(iVar1 + 0x80) + iVar7;
          iVar3 = 0;
          do {
            *(undefined4 *)(iVar5 + iVar3 * 4) = 0;
            *(undefined4 *)(iVar5 + 8 + iVar3 * 4) = 0;
            iVar3 = iVar3 + 1;
          } while (iVar3 < 2);
          iVar8 = iVar8 + 1;
          iVar7 = iVar7 + 0x24;
        } while (iVar8 < (int)(uint)*(ushort *)(iVar1 + 0x12));
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)(uint)**(byte **)(param_1 + 0x10));
  }
  cVar2 = FUN_006218c0();
  iVar6 = (int)cVar2;
  if ((iVar6 != 0) && (iVar6 < 9)) {
    FUN_006216f0(local_c,iVar6);
    iVar6 = FUN_004f8b10(local_c,&DAT_00755d68);
    if (iVar6 == 0) {
      FUN_006217e0();
      uVar4 = FUN_00517160(local_10,param_1 + 4,4);
      *(undefined4 *)(param_1 + 5000) = uVar4;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_14);
  return;
}

