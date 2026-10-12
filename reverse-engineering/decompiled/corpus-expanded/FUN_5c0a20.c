/* Ghidra pseudocode, not original source.
 * ev_e061930119eb38dbd4d1e45fa45a2093349cae71e0e7104520800438f1f9aa3c
 * Entry: 0x5c0a20; label: FUN_005c0a20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005c0a20(void)

{
  int iVar1;
  
  iVar1 = _rand();
  return (float10)((float)iVar1 / 32767.0);
}

