/* Ghidra pseudocode, not original source.
 * ev_347e1f77405e8535e9481480e28747f276aa6cf4478f7a28ab99ed1128324eac
 * Entry: 0x644410; label: FUN_00644410
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00644410(int param_1)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  if (DAT_00810194 != -1) {
    pcVar2 = &DAT_02913a58 + DAT_00810194 * 0x178;
    DAT_0291f798 = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,FUN_006443f0,"Type Name");
    if (DAT_0291f798 != 0) {
      uVar3 = FUN_00627c00(0,&DAT_008109d8,&LAB_00644390,"Name: ");
      FUN_00618e10(DAT_0291f798,uVar3);
      pcVar4 = (char *)(DAT_02900c84 + 0x4c);
      do {
        cVar1 = *pcVar2;
        *pcVar4 = cVar1;
        pcVar2 = pcVar2 + 1;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      *(undefined2 *)(DAT_02900c84 + 0x15a) = 0xf;
      FUN_006279b0(param_1,DAT_0291f798);
      *(int *)(DAT_0291f798 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_0291f798 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

