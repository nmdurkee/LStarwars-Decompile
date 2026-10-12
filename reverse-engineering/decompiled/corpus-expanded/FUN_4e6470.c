/* Ghidra pseudocode, not original source.
 * ev_9a3410a9c272a2064cc0564fa84db44ccced53000acc775659afcf5219797551
 * Entry: 0x4e6470; label: FUN_004e6470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e6470(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_004e6000(param_1,(int)DAT_007f1994);
  FUN_004e6260(param_1);
  iVar2 = DAT_0088a40c;
  iVar1 = DAT_0088a408;
  if (((DAT_00951b50 == 0) && (DAT_0088a408 != 0)) && (DAT_0088a40c != 0)) {
    *(undefined4 *)(DAT_0088a408 + 0x10) = *(undefined4 *)(DAT_0088a40c + 0x874);
    *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar2 + 0x878);
    *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(iVar2 + 0x87c);
  }
  return;
}

