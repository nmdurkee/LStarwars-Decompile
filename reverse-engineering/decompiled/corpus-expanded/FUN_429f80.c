/* Ghidra pseudocode, not original source.
 * ev_07ae9e2e04489686a5b927c1fa0593b6d570aedc464c7aee9c2d2b7a39d3047e
 * Entry: 0x429f80; label: FUN_00429f80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00429f80(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (((DAT_0087af5c != 0) && (iVar1 = FUN_0055f450(), *(int *)(iVar1 + 300) == DAT_0087af5c)) &&
     (iVar1 = FUN_004f8a70(param_1,"episodei\\ep1_podrace_"), iVar1 == param_1)) {
    iVar1 = FUN_004f1ff0("episodei\\ep1_podrace_");
    iVar1 = iVar1 + param_1;
    iVar2 = FUN_004f8b10(iVar1,"arrival1");
    if (((((iVar2 == 0) || (iVar2 = FUN_004f8b10(iVar1,"arrival2"), iVar2 == 0)) ||
         ((iVar2 = FUN_004f8b10(iVar1,"arrival3"), iVar2 == 0 ||
          ((iVar2 = FUN_004f8b10(iVar1,"arrival4"), iVar2 == 0 ||
           (iVar2 = FUN_004f8b10(iVar1,"intro"), iVar2 == 0)))))) ||
        (iVar2 = FUN_004f8b10(iVar1,"tuskenraiders"), iVar2 == 0)) ||
       ((iVar2 = FUN_004f8b10(iVar1,"outro1"), iVar2 == 0 ||
        (iVar1 = FUN_004f8b10(iVar1,"outro2"), iVar1 == 0)))) {
      FUN_004f1e80(param_1,"_sprint");
    }
  }
  return;
}

