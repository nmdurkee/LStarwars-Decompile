/* Ghidra pseudocode, not original source.
 * ev_ca5ea7f3b5788154105ce78c12a6b4d3dd45520787e3b427f0542ab309566885
 * Entry: 0x62a780; label: FUN_0062a780
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0062a780(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_2 != -1) {
    puVar2 = &param_2;
    iVar1 = param_2;
    do {
      FUN_0062a720(iVar1,param_1,0xffffffff);
      iVar1 = puVar2[1];
      puVar2 = puVar2 + 1;
    } while (iVar1 != -1);
  }
  return;
}

