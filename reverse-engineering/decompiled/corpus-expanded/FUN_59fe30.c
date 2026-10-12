/* Ghidra pseudocode, not original source.
 * ev_1b30ab9bd7d518785b9e88881958deca55ff5b776c2bbdcc158b73c997cdcb1d
 * Entry: 0x59fe30; label: FUN_0059fe30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059fe30(int param_1,int param_2)

{
  undefined4 *puVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((*(char *)(param_2 + 0x280) == '\0') || (*(char *)(param_2 + 0x280) == '\x01')) {
    *(int *)(&DAT_00956598 + *(char *)(param_2 + 0x280) * 0x38) = param_1;
    iVar5 = 0;
    (&DAT_009565cc)[*(char *)(param_2 + 0x280) * 0xe] = 0;
    iVar4 = 0;
    do {
      iVar3 = FUN_0054fa60();
      *(float *)(&DAT_009565c0 + (iVar5 + *(char *)(param_2 + 0x280) * 0xe) * 4) =
           (float)iVar3 * 1.5259022e-05 * 0.4 + 0.4;
      fVar2 = *(float *)(&DAT_009565c0 + (iVar5 + *(char *)(param_2 + 0x280) * 0xe) * 4);
      puVar1 = (undefined4 *)(&DAT_0095659c + *(char *)(param_2 + 0x280) * 0x38 + iVar4);
      iVar4 = iVar4 + 0xc;
      iVar5 = iVar5 + 1;
      *puVar1 = *(undefined4 *)(param_1 + 0x80);
      puVar1[2] = *(undefined4 *)(param_1 + 0x88);
      puVar1[1] = *(float *)(param_1 + 0x17c) +
                  fVar2 * (*(float *)(param_1 + 0x188) - *(float *)(param_1 + 0x17c));
    } while (iVar4 < 0x24);
  }
  if ((*(byte *)(param_2 + 0x1fc) & 0x80) != 0) {
    if (DAT_0087a7c4 == 0) {
      DAT_0087a7c4 = 1;
      _DAT_0087a7c0 = 1;
      return;
    }
    if (DAT_0087a7c4 == 1) {
      DAT_0087a7c4 = 2;
    }
    _DAT_0087a7c0 = 1;
  }
  return;
}

