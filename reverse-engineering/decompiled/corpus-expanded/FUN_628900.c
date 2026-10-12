/* Ghidra pseudocode, not original source.
 * ev_e165dd79ce50f74ce872f7d9e4945159ab28a1cd27d81db1142f7150b3bed141
 * Entry: 0x628900; label: FUN_00628900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00628900(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  iVar1 = *(int *)(param_2 + 0xc);
  iVar2 = *(int *)(iVar1 + 0x50);
  if (iVar2 != 0) {
    if ((*(int *)(param_2 + 8) == 10) || (*(int *)(param_2 + 8) == 0xb)) {
      FUN_0061a670(iVar2,*(undefined4 *)(param_2 + 0x54),*(undefined4 *)(param_2 + 0x58),
                   *(undefined4 *)(param_2 + 0x5c));
    }
    pcVar3 = *(code **)(iVar1 + 0x58);
    if (pcVar3 != (code *)0x0) {
      (*pcVar3)(param_1,param_2,param_3);
    }
  }
  FUN_006279f0(param_1);
  FUN_00624220(param_1);
  return;
}

