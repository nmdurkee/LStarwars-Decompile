/* Ghidra pseudocode, not original source.
 * ev_1545e5b34141c1614daa034024a98821bd7642306100b3a505193274c33334db
 * Entry: 0x4e2de0; label: FUN_004e2de0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e2de0(void)

{
  int iVar1;
  int iVar2;
  
  if (DAT_00889598 == 0) {
    DAT_00889598 = FUN_005aac00(DAT_0095df4c,"FreePalpatine",0);
  }
  if (DAT_00889590 == 0) {
    DAT_00889590 = FUN_005aac00(DAT_0095df4c,"DookuFight",0);
  }
  if (DAT_00951b50 != 0) {
    *(float *)(DAT_00889598 + 0x28) = (float)(int)*DAT_00889588;
    *(float *)(DAT_00889590 + 0x28) = (float)(int)DAT_00889588[1];
  }
  if (DAT_0088959c == 0) {
    DAT_0088959c = FUN_0055ce20((int)DAT_007f1a0c,0x400,1,1,0);
  }
  if (DAT_008895a0 == 0) {
    DAT_008895a0 = FUN_0051ac10(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),"Palpatine");
  }
  if (DAT_00889594 == 0) {
    DAT_00889594 = FUN_0055ce20((int)DAT_007f1a08,1,1,1,0);
  }
  iVar2 = DAT_008895a0;
  iVar1 = DAT_0088959c;
  if ((((DAT_0093b2a4 == 0) && (DAT_0088959c != 0)) && (DAT_008895a0 != 0)) &&
     ((DAT_00889598 != 0 && (*(float *)(DAT_00889598 + 0x28) < 2.0)))) {
    *(undefined4 *)(DAT_0088959c + 0x5c) = *(undefined4 *)(DAT_008895a0 + 0x10);
    *(undefined4 *)(iVar1 + 0x60) = *(undefined4 *)(iVar2 + 0x14);
    *(undefined4 *)(iVar1 + 100) = *(undefined4 *)(iVar2 + 0x18);
    *(undefined2 *)(DAT_0088959c + 0x27a) = *(undefined2 *)(DAT_008895a0 + 0x1c);
  }
  return;
}

