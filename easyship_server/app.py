from flask import Flask
from flask import render_template
import pickle
import networkx as nx
from networkx.algorithms.approximation import clique
import operator
import collections
from multiprocessing.pool import ThreadPool
from time import time as timer
from urllib2 import urlopen
import os
import json
from pprint import pprint
from pymongo import MongoClient
import datetime
import os
import re
import urllib2
import json
import pickle
from bson.objectid import ObjectId
from bs4 import BeautifulSoup
from flask import request
import requests
from twilio.rest import Client
app = Flask(__name__)
from flask.ext.rq import get_worker



@app.route('/', methods=['GET','POST'])
def hello(name=None):
	if request.method == 'POST':
		content=request.get_json()
		print content[0]
		easyship_response = {
		    "total_pages": 2,
		    "current_page": 1,
		    "shipments": [
		        {
		            "created_at": "2016-12-15T08:35:11.938Z",
		            "updated_at": "2016-12-15T08:35:12.079Z",
		            "easyship_shipment_id": "ESTEST00000",
		            "destination_name": "Aloha Chen",
		            "destination_address_line_1": "300 Park Avenue",
		            "destination_address_line_2": "null",
		            "destination_city": "New York",
		            "destination_state": "NY",
		            "destination_postal_code": "10022",
		            "destination_phone_number": "+1 234-567-890",
		            "destination_email_address": "api-support@easyship.com",
		            "platform_order_number": "#1234",
		            "platform_name": "Amazon",
		            "total_customs_value": 100,
		            "total_actual_weight": 1.2,
		            "total_dimensional_weight": 0.6,
		            "total_volumetric_weight": 1.2,
		            "is_insured": "false",
		            "currency": "SGD",
		            "origin_country": {
		                "name": "Singapore",
		                "alpha2": "SG"
		            },
		            "destination_country": {
		                "name": "United States",
		                "alpha2": "US"
		            },
		            "items": [
		                {
		                    "id": "a918ff21-fe35-4cf0-bf48-a9ff5335d20e",
		                    "description": "Silk dress",
		                    "sku": "test",
		                    "width": 15,
		                    "length": 20,
		                    "height": 10,
		                    "actual_weight": 1.2,
		                    "dimensional_weight": 0.6,
		                    "volumetric_weight": 1.2,
		                    "declared_customs_value": 100,
		                    "declared_currency": "SGD",
		                    "origin_customs_value": 100,
		                    "origin_currency": "SGD",
		                    "category": "fashion"
		                },
		              {
		                    "id": "0f921583-26d4-4341-bce7-0995237ffa5c",
		                    "description": "Cotton dress",
		                    "sku": "test2",
		                    "width": 15,
		                    "length": 20,
		                    "height": 10,
		                    "actual_weight": 1.2,
		                    "dimensional_weight": 0.6,
		                    "volumetric_weight": 1.2,
		                    "declared_customs_value": 100,
		                    "declared_currency": "SGD",
		                    "origin_customs_value": 100,
		                    "origin_currency": "SGD",
		                    "category": "fashion"
		                }
		            ],
		            "box": {
		                "name": "null",
		                "length": 20,
		                "width": 15,
		                "height": 10
		            },
		            "selected_courier": {
		              "id": "2a17f7aa-51f7-4d36-bca8-e77c164cb52a",
		              "name": "DHL Express",
		              "min_delivery_time": 2,
		              "max_delivery_time": 3,
		              "shipment_charge": 284.9,
		              "fuel_surcharge": 32.05125,
		              "remote_area_surcharge": 0,
		              "shipment_charge_total": 316.95125,
		              "warehouse_handling_fee": 0,
		              "insurance_fee": 0,
		              "import_tax_charge": 0,
		              "import_duty_charge": 0,
		              "ddp_handling_fee": 0,
		              "total_charge": 316.95,
		              "is_above_threshold": "false",
		              "effective_incoterms": "DDU",
		              "estimated_import_tax": 0,
		              "estimated_import_duty": 0,
		              "courier_does_pickup": "false",
		              "courier_dropoff_url": "https://www.easyship.com/drop-off/dhl/hk",
		              "courier_remarks": "null",
		              "payment_recipient": "Easyship"
		            },
		            "rates": [
		                {
		                    "courier_id": "462e4de9-0762-4c71-9cad-d6495ce364fb",
		                    "courier_name": "DHL Express",
		                    "min_delivery_time": 2,
		                    "max_delivery_time": 3,
		                    "value_for_money_rank": 1,
		                    "delivery_time_rank": 1,
		                    "shipment_charge": 68.082,
		                    "fuel_surcharge": 8.51025,
		                    "remote_area_surcharge": "null",
		                    "shipment_charge_total": 76.59225,
		                    "warehouse_handling_fee": 0,
		                    "insurance_fee": 0,
		                    "ddp_handling_fee": 0,
		                    "import_tax_charge": 0,
		                    "import_duty_charge": 0,
		                    "total_charge": 76.59,
		                    "is_above_threshold": "false",
		                    "effective_incoterms": "DDU",
		                    "estimated_import_tax": 0,
		                    "estimated_import_duty": 0,
		                    "courier_does_pickup": "true",
		                    "courier_dropoff_url": "null",
		                    "tracking_rating": 3,
		                    "easyship_rating": 4.4,
		                    "courier_remarks": "null",
		                    "payment_recipient": "Easyship"
		               }
		            ]
		        }
		    ]
		}
		account = "AC8639e4561fdd678385f67e5cda339d5b"
		token = "0478df1b7d88d282c0d7645459fb59ee"
		client = Client(account, token)
		print easyship_response['shipments'][0]['destination_phone_number']
		message = client.messages.create(to="+6583000105", from_="+16266237170",
                                 body="Your shipment is in Hollywood, FL, US")
		return json.dumps(['Hello'])



# from flask import Flask
# app = Flask(__name__)

# @app.route('/')
# def hello_world():
#    return render_template('index.html')

if __name__ == '__main__':
   app.run(debug = True)
