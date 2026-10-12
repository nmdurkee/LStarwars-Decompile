/* Ghidra pseudocode, not original source.
 * ev_d7fef5854a4ea50d405948ed3aa82c9004ffbc8626dda7a7f3cbba7e59036064
 * Entry: 0x5900e0; label: FUN_005900e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005900e0(int *param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) {
    FUN_005a15e0(*(undefined4 *)(iVar1 + 0x10),param_2);
    *(ushort *)(iVar1 + 0x7a) =
         *(ushort *)(iVar1 + 0x7a) ^ (byte)((param_2 != 0) * '\x02' ^ *(byte *)(iVar1 + 0x7a)) & 2;
  }
  return;
}

