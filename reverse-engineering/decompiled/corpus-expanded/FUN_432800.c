/* Ghidra pseudocode, not original source.
 * ev_a581b26cc49c1240ca9fc8201471236b1c0a2571dfff42173a4e3442f2e0fd27
 * Entry: 0x432800; label: FUN_00432800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00432800(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_0055e2b0(param_1);
  if (iVar1 != 0) {
    *(uint *)(iVar1 + 0xe20) =
         *(uint *)(iVar1 + 0xe20) ^ (param_2 << 0x10 ^ *(uint *)(iVar1 + 0xe20)) & 0x10000;
    if (param_2 == 0) {
      *(undefined4 *)(iVar1 + 0xd3c) = 0;
    }
    else {
      *(undefined4 *)(iVar1 + 0xd3c) = 0x3f800000;
      if ((*(byte *)(iVar1 + 0x1fc) & 0x80) == 0) {
        *(undefined4 *)(iVar1 + 0xecc) = _DAT_007f6730;
        return;
      }
    }
  }
  return;
}

