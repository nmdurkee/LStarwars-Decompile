/* Ghidra pseudocode, not original source.
 * ev_ce5edc1561b77c28ba497ac7e0a731ad3290827c35b207bcfcd23dc4a7952c7a
 * Entry: 0x57ad40; label: FUN_0057ad40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057ad40(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_007622ac);
    if (iVar1 == 0) {
      *(uint *)(DAT_00951c4c + 0x50) = *(uint *)(DAT_00951c4c + 0x50) | 0x8000;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      *(uint *)(DAT_00951c4c + 0x50) = *(uint *)(DAT_00951c4c + 0x50) & 0xffff7fff;
    }
  }
  return;
}

