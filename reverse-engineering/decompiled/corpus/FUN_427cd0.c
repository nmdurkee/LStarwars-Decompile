/* Ghidra analysis pseudocode, not original source.
 * ev_310631bb624827f7a98d5acd3a21e7258cb6e2cd16a2b6553760fed88e2e9667
 * Entry: 0x427cd0; label: FUN_00427cd0
 */

void FUN_00427cd0(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 local_c [12];
  
  iVar4 = (&DAT_0093d7f0)[param_1];
  if (iVar4 != 0) {
    if (param_3 == 0) {
      if (*(int *)(iVar4 + 0xcd0) == 0) {
        FUN_004f42d0((*(int *)(iVar4 + 0xca4) + -0x9253b0) / 0x60,0);
      }
      FUN_00547930(0x20,iVar4 + 0x80,0,0);
    }
    FUN_004882d0(iVar4,1);
    uVar1 = *(undefined2 *)(iVar4 + 0xe1a);
    uVar2 = *(undefined2 *)(iVar4 + 0xe18);
    uVar3 = *(undefined2 *)(iVar4 + 0xe1c);
    FUN_0049c4e0(iVar4);
    if (DAT_00951288 != 0) {
      FUN_004148a0(iVar4 + 0x6c4,*(undefined4 *)(iVar4 + 0x54));
      *(undefined2 *)(iVar4 + 0xe1a) = uVar1;
      *(undefined2 *)(iVar4 + 0xe18) = uVar2;
      *(undefined2 *)(iVar4 + 0xe1c) = uVar3;
    }
    *(uint *)(iVar4 + 0x1fc) = *(uint *)(iVar4 + 0x1fc) & 0xffffff7f;
    FUN_00415000(iVar4);
    if (DAT_00951288 != 0) {
      FUN_00427c70(iVar4);
    }
    if ((*(char *)(iVar4 + 0x28b) == '\0') && (*(char *)(iVar4 + 0x7b5) != '+')) {
      (&DAT_0093d518)[param_1 * 0x10] = *(undefined1 *)(iVar4 + 0x107f);
    }
    else {
      (&DAT_0093d518)[param_1 * 0x10] = *(undefined1 *)(iVar4 + 0x107e);
    }
    *(undefined4 *)(iVar4 + 0xdec) = 0;
    if (DAT_00951288 == 0) {
      uVar5 = 0x3f800000;
    }
    else {
      uVar5 = 0x3f000000;
    }
    FUN_0054a3e0(PTR_DAT_008021b4,uVar5,0,1);
    if (param_2 != 0) {
      FUN_0055c560(1);
      FUN_006d6170(0);
    }
    if ((&DAT_0093d7f0)[param_1 == 0] != 0) {
      FUN_005b3800(local_c,(&DAT_0093d7f0)[param_1 == 0] + 0x80,PTR_DAT_008021b4 + 0x11c);
      iVar4 = FUN_0067b430(PTR_DAT_008021b4 + 0x11c,local_c,0,0x3f800000,0,0x1f);
      if (iVar4 != 0) {
        FUN_0054a2f0(PTR_DAT_008021b4);
      }
    }
  }
  return;
}

