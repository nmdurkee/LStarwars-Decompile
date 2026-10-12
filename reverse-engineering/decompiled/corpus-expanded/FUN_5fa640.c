/* Ghidra pseudocode, not original source.
 * ev_63eb9bd68174043ae1497f20c7ab174ab5c86e6d078dec24e1a9d3709ec9fcaa
 * Entry: 0x5fa640; label: FUN_005fa640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fa640(int param_1,undefined2 *param_2,char *param_3)

{
  undefined4 in_EAX;
  undefined4 uVar1;
  
  uVar1 = CONCAT31((int3)((uint)in_EAX >> 8),*param_3);
  if (*param_3 == '\0') {
    *param_2 = 0;
    return;
  }
  do {
    uVar1 = FUN_005d0aa0(*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x10),
                         CONCAT22((short)((uint)uVar1 >> 0x10),(short)(char)uVar1));
    param_3 = param_3 + 1;
    *param_2 = (short)uVar1;
    uVar1 = CONCAT31((int3)((uint)uVar1 >> 8),*param_3);
    param_2 = param_2 + 1;
  } while (*param_3 != '\0');
  *param_2 = 0;
  return;
}

