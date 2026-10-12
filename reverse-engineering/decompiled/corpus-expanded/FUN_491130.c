/* Ghidra pseudocode, not original source.
 * ev_96df89c4daae28ff35d834560256e783041bc073304993e474c02e03eab098bd
 * Entry: 0x491130; label: FUN_00491130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00491130(int *param_1,int param_2)

{
  int iVar1;
  
  if (((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) &&
     (*(ushort *)(iVar1 + 0x94) =
           *(ushort *)(iVar1 + 0x94) ^ (byte)((param_2 != 0) << 7 ^ *(byte *)(iVar1 + 0x94)) & 0x80,
     param_2 != 0)) {
    FUN_00491010();
  }
  return;
}

