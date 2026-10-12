/* Ghidra pseudocode, not original source.
 * ev_856f9c42d20ec6ba6350b0d1cce9335bfe45cee30263bcd63df252d3cb890b58
 * Entry: 0x527800; label: FUN_00527800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00527800(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_009238e4 + 0x4381c);
  cVar1 = *(char *)(iVar2 + 0x49);
  if ((iVar2 != 0) && (param_2 != 0)) {
    *(undefined1 *)(iVar2 + 0x49) = *(undefined1 *)(param_2 + 0xc);
  }
  iVar2 = *(int *)(DAT_009238e4 + 0x4381c);
  if (*(char *)(iVar2 + 0x49) == '\0') {
    if (cVar1 != '\0') {
      if (*(float *)(iVar2 + 0x44) < *(float *)(iVar2 + 0x40)) {
        *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar2 + 0x40);
        return;
      }
      *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar2 + 0x44);
      return;
    }
  }
  else if (cVar1 == '\0') {
    *(undefined4 *)(iVar2 + 0x44) = *(undefined4 *)(iVar2 + 0x14);
    *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x40) =
         *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x44);
  }
  return;
}

