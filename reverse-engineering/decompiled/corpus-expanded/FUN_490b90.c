/* Ghidra pseudocode, not original source.
 * ev_96df89c4daae28ff35d834560256e783041bc073304993e474c02e03eab098bd
 * Entry: 0x490b90; label: FUN_00490b90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00490b90(int *param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  
  uVar1 = *(ushort *)(*param_1 + 0x94);
  if ((char)uVar1 < '\0') {
    if (param_2 != 0) {
      if (param_2 == 1) {
        uVar1 = uVar1 & 4;
      }
      else {
        if (param_2 != 2) {
          return 0;
        }
        uVar1 = uVar1 & 8;
      }
      if (uVar1 == 0) {
        return 0;
      }
    }
    iVar2 = FUN_00490b40(*param_1);
    if (iVar2 != 0) {
      return 1;
    }
  }
  return 0;
}

