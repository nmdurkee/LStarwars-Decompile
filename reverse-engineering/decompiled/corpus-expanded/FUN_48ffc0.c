/* Ghidra pseudocode, not original source.
 * ev_96df89c4daae28ff35d834560256e783041bc073304993e474c02e03eab098bd
 * Entry: 0x48ffc0; label: FUN_0048ffc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0048ffc0(int param_1)

{
  int iVar1;
  
  if (((*(char *)(param_1 + 0x7b5) == 'J') && (iVar1 = *(int *)(param_1 + 0x798), iVar1 != 0)) &&
     ((*(byte *)(iVar1 + 0x94) & 2) == 0)) {
    *(ushort *)(iVar1 + 0x94) = *(ushort *)(iVar1 + 0x94) & 0xfffe;
  }
  return;
}

