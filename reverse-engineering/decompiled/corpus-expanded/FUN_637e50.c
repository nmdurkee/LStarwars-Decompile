/* Ghidra pseudocode, not original source.
 * ev_3cc3478cfa8c26bd4fafca5bd3c3e065fb7e5c3537b7c6265584e6b0ffbf613e
 * Entry: 0x637e50; label: FUN_00637e50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00637e50(undefined4 *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  
  cVar2 = *(char *)((int)param_1 + 0x79);
  if ((cVar2 != -1) && (*(char *)((int)param_1 + 0x7a) == -1)) {
    do {
      FUN_00637e50(cVar2 * 0x8c + 4 + DAT_0291389c);
      cVar2 = *(char *)((int)param_1 + 0x79);
    } while (cVar2 != -1);
  }
  if ((*(char *)((int)param_1 + 0x7a) != -1) &&
     (*(undefined1 *)(*(char *)((int)param_1 + 0x7a) * 0x8c + 0x7d + DAT_0291389c) =
           *(undefined1 *)((int)param_1 + 0x79), *(char *)((int)param_1 + 0x79) != -1)) {
    *(undefined1 *)(*(char *)((int)param_1 + 0x79) * 0x8c + 0x7e + DAT_0291389c) =
         *(undefined1 *)((int)param_1 + 0x7a);
  }
  iVar4 = ((int)param_1 + (-4 - DAT_0291389c)) / 0x8c;
  uVar3 = DAT_0291389c + 4;
  iVar6 = DAT_0291389c;
  if (uVar3 < DAT_0291389c + 0x4604U) {
    do {
      if (iVar4 <= *(char *)(uVar3 + 0x79)) {
        *(char *)(uVar3 + 0x79) = *(char *)(uVar3 + 0x79) + -1;
        iVar6 = DAT_0291389c;
      }
      if (iVar4 <= *(char *)(uVar3 + 0x7a)) {
        *(char *)(uVar3 + 0x7a) = *(char *)(uVar3 + 0x7a) + -1;
        iVar6 = DAT_0291389c;
      }
      uVar3 = uVar3 + 0x8c;
    } while (uVar3 < iVar6 + 0x4604U);
  }
  puVar1 = param_1;
  if ((undefined4 *)(iVar6 + 0x4604) <= param_1) {
    *(undefined1 *)(param_1 + -0xd) = 0;
    return;
  }
  do {
    if (*(char *)(param_1 + 0x16) == '\0') break;
    puVar5 = puVar1 + 0x23;
    puVar7 = param_1;
    for (iVar4 = 0x23; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
    param_1 = param_1 + 0x23;
    puVar1 = puVar1 + 0x23;
  } while (param_1 < (undefined4 *)(DAT_0291389c + 0x4604));
  *(undefined1 *)(param_1 + -0xd) = 0;
  return;
}

