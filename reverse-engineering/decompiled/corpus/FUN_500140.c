/* Ghidra analysis pseudocode, not original source.
 * ev_b66c424cb3575f57780fb90d996a1c84f19feddd26ab04bda15cdd4040b17690
 * Entry: 0x500140; label: FUN_00500140
 */

void FUN_00500140(uint *param_1,uint *param_2)

{
  int iVar1;
  undefined2 *puVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  
  if ((((4 < (*param_1 & 0xff)) && (param_1[4] != 0)) && (*(int *)(param_1[4] + 0x20) != 0)) &&
     ((int *)param_1[7] != (int *)0x0)) {
    iVar1 = *(int *)param_1[7];
    uVar3 = *param_2 + 1 & 0xfffffffe;
    *param_2 = uVar3;
    param_1[0x15] = uVar3;
    iVar4 = 0;
    if (*(char *)(param_1[7] + 8) != '\0') {
      pbVar5 = (byte *)(iVar1 + 0x59);
      do {
        if ((*(byte *)(*(int *)(param_1[7] + 4) + 4 + (uint)*pbVar5 * 0xc) & 8) != 0) {
          puVar2 = (undefined2 *)*param_2;
          *param_2 = (uint)(puVar2 + 1);
          *puVar2 = (short)iVar4;
        }
        iVar4 = iVar4 + 1;
        pbVar5 = pbVar5 + 100;
      } while (iVar4 < (int)(uint)*(byte *)(param_1[7] + 8));
    }
  }
  return;
}

