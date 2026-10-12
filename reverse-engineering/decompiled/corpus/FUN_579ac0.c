/* Ghidra analysis pseudocode, not original source.
 * ev_0fe45ae231fd2dfd40158a7785e6912069fa204ac07eb0ac56676de85047f6bb
 * Entry: 0x579ac0; label: FUN_00579ac0
 */

void FUN_00579ac0(int param_1)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = FUN_004f7fb0(param_1);
  while (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"xspeed");
    if (iVar1 == 0) {
      fVar2 = (float10)FUN_004f8100(param_1);
      *(float *)(DAT_00951b74 + 0xd0) = (float)fVar2;
    }
    else {
      iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"zspeed");
      if (iVar1 == 0) {
        fVar2 = (float10)FUN_004f8100(param_1);
        *(float *)(DAT_00951b74 + 0xd4) = (float)fVar2;
      }
    }
    iVar1 = FUN_004f7fb0(param_1);
  }
  return;
}

