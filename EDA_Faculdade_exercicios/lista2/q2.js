class Network{
	constructor(pPeople){
		this.peopleReference = pPeople ;
		this.friendsNetwork = [];
	}
	create(){
		for(let i = 0; i < this.peopleReference.length; i++){
			this.friendsNetwork.push(new Array(this.peopleReference.length)
									 .fill(0));

		}
	}
	follow(friend1,friend2){
		const index1 = this.peopleReference.indexOf(friend1) ;
		const index2 = this.peopleReference.indexOf(friend2);
		this.friendsNetwork[index1]
								 [index2] = 1;
		this.friendsNetwork[index2]
								 [index1] = 1;
	}
	searchFriends(nome){
		const index = this.peopleReference.indexOf(nome);
		if(index < 0){
			console.log("Essa pessoa não existe na nossa rede social");
			return;
		}
		const aux = [];

		for(let i = 0; i < this.peopleReference.length; i++){
				if(this.friendsNetwork[i][index]){
					aux.push(this.peopleReference[i]);
				}
		}
		console.log("Os amigos de " + nome + " são " + aux);	
	}
	snapshotGraph(){
		for(let i = 0; i < this.peopleReference.length; i++){
			for(let j = 0; j < this.peopleReference.length; j++){
				if(this.friendsNetwork[i][j] == 1){
					this.friendsNetwork[i][j] = (this.peopleReference[j]);
				}

			}
		}
	console.log(this.friendsNetwork);
	}
	snapshotArray(){
		//Não sei !!!
	}

};

const newNetwork = new Network(["Joédyson","Jonatan","Elivelton","Jorge","Carvalho"]); 
newNetwork.create();
newNetwork.follow("Joédyson","Jonatan");
newNetwork.follow("Joédyson","Jorge");
newNetwork.follow("Joédyson","Elivelton");
newNetwork.follow("Jonatan","Carvalho");
newNetwork.follow("Jonatan","Jorge");
newNetwork.follow("Elivelton","Jorge");
newNetwork.follow("Jorge","Carvalho");
newNetwork.searchFriends("Joédyson");
newNetwork.searchFriends("Jonatan");
newNetwork.snapshotGraph();



