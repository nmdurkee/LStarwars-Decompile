/* Ghidra pseudocode, not original source.
 * ev_96df89c4daae28ff35d834560256e783041bc073304993e474c02e03eab098bd
 * Entry: 0x490080; label: FUN_00490080
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00490080(int *param_1,uint param_2,byte param_3)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) {
    if ((param_3 & 1) != 0) {
      if ((*(byte *)(iVar1 + 0x94) & 0x80) != 0) {
        return param_2;
      }
      return (uint)(param_2 == 0);
    }
    *(ushort *)(iVar1 + 0x94) =
         *(ushort *)(iVar1 + 0x94) ^ (byte)((param_2 == 0) << 7 ^ *(byte *)(iVar1 + 0x94)) & 0x80;
  }
  return 1;
}

