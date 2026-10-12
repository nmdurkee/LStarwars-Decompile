/* Ghidra pseudocode, not original source.
 * ev_8b33ce688355ba097f8d2f702831fda396d81ac3370e92e38da24fe76235d9ff
 * Entry: 0x466060; label: FUN_00466060
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00466060(int param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  
  *(ushort *)(param_2 + 0xc) = *(ushort *)(param_2 + 0xc) | 1;
  uVar1 = *(ushort *)(param_2 + 0xc);
  if (DAT_008765cc != 0) {
    *(ushort *)(param_2 + 0xc) = uVar1 & 0xfffd;
    *(undefined4 *)(param_2 + 0x10) = param_3;
    return;
  }
  *(ushort *)(param_2 + 0xc) = (byte)(*(char *)(param_1 + 0x118) * '\x02' ^ (byte)uVar1) & 2 ^ uVar1
  ;
  *(undefined4 *)(param_2 + 0x10) = param_3;
  return;
}

