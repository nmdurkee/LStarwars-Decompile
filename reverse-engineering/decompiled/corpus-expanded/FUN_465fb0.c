/* Ghidra pseudocode, not original source.
 * ev_8b33ce688355ba097f8d2f702831fda396d81ac3370e92e38da24fe76235d9ff
 * Entry: 0x465fb0; label: FUN_00465fb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00465fb0(int *param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) {
    FUN_005a15e0(*(undefined4 *)(iVar1 + 0x1c),param_2);
    *(ushort *)(iVar1 + 0x2a) =
         *(ushort *)(iVar1 + 0x2a) ^ (byte)((param_2 != 0) * '\x02' ^ *(byte *)(iVar1 + 0x2a)) & 2;
  }
  return;
}

