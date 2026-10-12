/* Ghidra pseudocode, not original source.
 * ev_e1a2c2f5e90166cb5ef7597416632d6b9968be44632f575ffe69a13c5b8ac55c
 * Entry: 0x55f500; label: FUN_0055f500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0055f500(undefined *param_1)

{
  undefined *puVar1;
  
  puVar1 = &DAT_0093d858;
  if (param_1 == &DAT_0093d858) {
    puVar1 = &DAT_00942a04;
  }
  if (*(int *)(puVar1 + 0x110) != 0) {
    return *(undefined4 *)(puVar1 + 0x11c);
  }
  return 0xffffffff;
}

