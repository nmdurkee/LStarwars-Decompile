/* Ghidra pseudocode, not original source.
 * ev_8e73b717ff009f07746f1c65dd4e3482676ea3fff3015cb29c9ed201b1c71a72
 * Entry: 0x54b3d0; label: FUN_0054b3d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0054b3d0(int param_1,int param_2)

{
  int iVar1;
  
  if ((((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) && (*(char *)(param_1 + 0x671) != -1)) &&
     (iVar1 = *(char *)(param_1 + 0x671) * 0x13c + **(int **)(PTR_DAT_00802c54 + 0x2988),
     (*(byte *)(iVar1 + 0x68) & 0x40) != 0)) {
    return (uint)*(ushort *)(iVar1 + 0x6e) + (uint)*(ushort *)(param_1 + 0x696) +
           (uint)*(ushort *)(param_2 + 0x26);
  }
  return (uint)*(ushort *)(param_2 + 0x26) + *(int *)(PTR_DAT_008021b4 + 0x1fc);
}

