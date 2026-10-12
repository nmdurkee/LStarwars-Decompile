/* Ghidra pseudocode, not original source.
 * ev_9931c233bc23f2b366e36cd20edde6ea49582f2b0a176997d8924d6b396dfde7
 * Entry: 0x58e360; label: FUN_0058e360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0058e360(int param_1,undefined1 param_2)

{
  int iVar1;
  
  *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) | 0x40;
  *(byte *)(param_1 + 0xe34) = *(byte *)(param_1 + 0xe34) | 5;
  *(undefined1 *)(param_1 + 0xe35) = param_2;
  if ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) {
    iVar1 = FUN_0055f320(param_1);
    if (iVar1 != 0) {
      *(char *)(param_1 + 0xe35) = *(char *)(param_1 + 0xe35) * '\x02';
    }
  }
  FUN_0058e040(param_1);
  return;
}

