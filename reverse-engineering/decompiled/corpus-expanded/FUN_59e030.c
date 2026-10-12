/* Ghidra pseudocode, not original source.
 * ev_57e4595202f6848139a561b6e4253d561eb3ad03e2f9632ed29ba9ff4f0bafc7
 * Entry: 0x59e030; label: FUN_0059e030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059e030(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  code *pcVar2;
  
  if ((param_2 != 0) && (*(char *)(param_2 + 3) == '\x02')) {
    for (puVar1 = *(undefined4 **)(param_2 + 0xc); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      if ((puVar1[3] != 0) && (pcVar2 = *(code **)(puVar1[3] + 4), pcVar2 != (code *)0x0)) {
        (*pcVar2)(param_1,param_2,puVar1[1],puVar1[2]);
      }
    }
  }
  return;
}

