/* Ghidra pseudocode, not original source.
 * ev_08b01c57e23761db39961ff885ea8d3cae9c908a4b5feb85ed876c23ab277753
 * Entry: 0x610570; label: FUN_00610570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00610570(byte *param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(&DAT_0080ed78 + (uint)*param_1 * 4) >> 8 ^
          *(uint *)(&DAT_0080ed78 +
                   ((uint)param_1[1] ^ *(uint *)(&DAT_0080ed78 + (uint)*param_1 * 4) & 0xff) * 4);
  return uVar1 >> 8 ^ *(uint *)(&DAT_0080ed78 + ((uint)param_1[2] ^ uVar1 & 0xff) * 4);
}

