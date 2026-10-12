/* Ghidra pseudocode, not original source.
 * ev_4cd49ed3a66acf658154edf3373401ea6a3421cc138b0b37f784f3d811d3c9f8
 * Entry: 0x503820; label: FUN_00503820
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00503820(void)

{
  undefined1 *puVar1;
  byte *pbVar2;
  int *piVar3;
  int *piVar4;
  int in_EAX;
  int iVar5;
  short *psVar6;
  int iVar7;
  char local_5;
  int local_4;
  
  piVar3 = *(int **)(in_EAX + 0xac);
  piVar4 = *(int **)(*(int *)(in_EAX + 0x58) + 0x24);
  if (0 < *piVar4) {
    local_4 = 0;
    iVar7 = 0;
    do {
      psVar6 = (short *)(piVar4[1] + local_4);
      puVar1 = (undefined1 *)(piVar3[1] + iVar7 * 4);
      *puVar1 = 0;
      iVar5 = FUN_005da520(*(undefined4 *)(psVar6 + 4),puVar1,&local_5,0x3f800000);
      if (iVar5 != 0) {
        pbVar2 = (byte *)(*(int *)(*piVar3 + 0xc) + 2 + *psVar6 * 4);
        if (local_5 == '\0') {
          *pbVar2 = *pbVar2 & 0xfe;
        }
        else {
          *pbVar2 = *pbVar2 | 1;
        }
      }
      local_4 = local_4 + 0xc;
      iVar7 = iVar7 + 1;
    } while (iVar7 < *piVar4);
  }
  return;
}

