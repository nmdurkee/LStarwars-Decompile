/* Ghidra pseudocode, not original source.
 * ev_f26efce709548f397f112d14bef56d8f0f3486015c16e671b302622d1d4cb319
 * Entry: 0x650430; label: FUN_00650430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00650430(char *param_1)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = 0;
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    if ((byte)(cVar1 + 0x9fU) < 0x1a) {
      cVar1 = cVar1 + -0x20;
    }
    uVar2 = uVar2 << 8 ^ *(uint *)(DAT_02947d80 + ((int)cVar1 ^ uVar2 >> 0x18) * 4);
    cVar1 = *param_1;
  }
  return uVar2;
}

