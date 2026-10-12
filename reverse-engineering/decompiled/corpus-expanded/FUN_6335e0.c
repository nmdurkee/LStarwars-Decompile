/* Ghidra pseudocode, not original source.
 * ev_11aaf33bc566dbb5337d0358c8c7e7b90799e20019d0aefa05560726d7209bd1
 * Entry: 0x6335e0; label: FUN_006335e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006335e0(int param_1)

{
  int in_ECX;
  
  if ((param_1 != 0) && (*(int *)(in_ECX + 0xc) < *(int *)(in_ECX + 8))) {
    *(int *)(*(int *)(in_ECX + 4) + *(int *)(in_ECX + 0xc) * 4) = param_1;
    *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + 1;
  }
  *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + *(int *)(in_ECX + 0x14);
  *(undefined4 *)(in_ECX + 0x14) = 0;
  return;
}

