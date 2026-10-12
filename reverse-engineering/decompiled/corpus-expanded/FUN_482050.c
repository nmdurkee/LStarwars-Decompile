/* Ghidra pseudocode, not original source.
 * ev_6d95b912f1db8f5f9ae5a1d448774b8e294221a9d492d15be8ca5acea434db46
 * Entry: 0x482050; label: FUN_00482050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00482050(int *param_1)

{
  if (((*(byte *)(*param_1 + 0x17) & 2) != 0) && ((*(byte *)(*param_1 + 0x17) & 1) != 0)) {
    return 1;
  }
  return 0;
}

