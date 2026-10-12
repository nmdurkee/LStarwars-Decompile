/* Ghidra pseudocode, not original source.
 * ev_856f9c42d20ec6ba6350b0d1cce9335bfe45cee30263bcd63df252d3cb890b58
 * Entry: 0x529050; label: FUN_00529050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00529050(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 uVar2;
  
  iVar1 = DAT_009238e4;
  if (*(int *)(DAT_009238e4 + 0x371b0) != 0) {
    uVar2 = FUN_006e6b90();
    *(undefined1 *)(*(int *)(iVar1 + 0x371b0) + 0x8e) = uVar2;
    iVar1 = *(int *)(DAT_009238e4 + 0x371b0);
    if (*(char *)(iVar1 + 0x8e) < *(char *)(iVar1 + 0x8d)) {
      *(undefined1 *)(iVar1 + 0x8e) = *(undefined1 *)(iVar1 + 0x8d);
      FUN_0061d850(param_2,(float)(int)*(char *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x8e));
    }
  }
  return;
}

