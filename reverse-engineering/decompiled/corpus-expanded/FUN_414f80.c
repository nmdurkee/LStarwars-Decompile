/* Ghidra pseudocode, not original source.
 * ev_c5aa9bb8cc1ea02955c57ce11c44cd7d2d7b8bb5b9f56b563e0c53fc6061ed49
 * Entry: 0x414f80; label: FUN_00414f80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00414f80(int param_1)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  undefined8 uVar4;
  
  iVar1 = DAT_0093d504;
  iVar3 = 0;
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x2808) = 0;
    *(undefined4 *)(param_1 + 0x280c) = 0;
    if (0 < DAT_0093d500) {
      puVar2 = (uint *)(iVar1 + 0x1f8);
      do {
        if ((((puVar2[1] & 1) != 0) && ((*puVar2 & 0x400) != 0)) &&
           (*(char *)((int)puVar2 + 0x20e) == '\x04')) {
          uVar4 = __allshl();
          *(uint *)(param_1 + 0x2808) = *(uint *)(param_1 + 0x2808) | (uint)uVar4;
          *(uint *)(param_1 + 0x280c) =
               *(uint *)(param_1 + 0x280c) | (uint)((ulonglong)uVar4 >> 0x20);
        }
        iVar3 = iVar3 + 1;
        puVar2 = puVar2 + 0x436;
      } while (iVar3 < DAT_0093d500);
    }
  }
  return;
}

