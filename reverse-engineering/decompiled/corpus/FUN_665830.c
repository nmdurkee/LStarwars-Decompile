/* Ghidra analysis pseudocode, not original source.
 * ev_280130a43e77cd6b8822caba528fd01ad8a7c5be61051c42bd6bb5c51ef00c77
 * Entry: 0x665830; label: FUN_00665830
 */

void FUN_00665830(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x80000000;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  local_4 = 0x80404040;
  iVar1 = *(int *)(DAT_0296209c +
                  *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4) *
                  4);
  DAT_02962a5c = FUN_00619250(0x46,0x46,0xb4,200,DAT_02912e80,&LAB_00665810,"Sound ID");
  if (DAT_02962a5c != 0) {
    uVar2 = FUN_00627b80(*(int *)(param_2 + 0xc) * 0x10000 + 9999,&local_10,
                         *(int *)(iVar1 + 0x3e0 + *(int *)(param_2 + 0xc) * 0xc) == -1,0,
                         &LAB_00665470,&DAT_007600a0);
    FUN_00618e10(DAT_02962a5c,uVar2);
    iVar4 = 0;
    iVar3 = 0;
    do {
      if (*(int *)(DAT_02947b74 + iVar3) != 0) {
        bVar5 = *(int *)(iVar1 + 0x3e0 + *(int *)(param_2 + 0xc) * 0xc) == iVar4;
        uVar2 = FUN_00627b80(*(int *)(param_2 + 0xc) * 0x10000 + iVar4,&local_10,bVar5,1,
                             &LAB_00665470,*(int *)(DAT_02947b74 + iVar3));
        FUN_00618e10(DAT_02962a5c,uVar2);
        if (bVar5) {
          *(undefined4 *)(DAT_02962a5c + 8) = DAT_02900c84;
        }
      }
      iVar3 = iVar3 + 0x40;
      iVar4 = iVar4 + 1;
    } while (iVar3 < 0x19000);
    FUN_006279b0(param_1,DAT_02962a5c);
    *(int *)(DAT_02962a5c + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_02962a5c + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

